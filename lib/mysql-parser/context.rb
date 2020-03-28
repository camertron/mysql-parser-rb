module MySqlParser
  class Context
    include StringHelpers

    attr_reader :name, :cpp_parser_source

    def initialize(name, cpp_parser_source)
      @name = name
      @cpp_parser_source = cpp_parser_source
    end

    def each_context_method
      return to_enum(__method__) unless block_given?

      context_methods.each do |ctx_method|
        yield ctx_method if define?(ctx_method)
      end
    end

    def proxy_class_variable
      @proxy_class_variable ||= "rb_c#{name}"
    end

    def proxy_class_header
      @proxy_class_header ||= begin
        method_signatures = each_context_method
          .map { |ctx_method| "  Object #{ctx_method.cpp_name}(#{ctx_method.raw_args});" }
          .join("\n")

        <<~END
          class #{name}Proxy : public MySqlParser::#{name} {
          public:
          #{method_signatures}
          };
        END
      end
    end

    def conversions
      @class_conversions ||= <<~END
        template <>
        Object to_ruby<MySqlParser::#{name}*>(MySqlParser::#{name}* const &x) {
          if (!x) return Nil;
          return Data_Object<MySqlParser::#{name}>(x, #{proxy_class_variable}, nullptr, nullptr);
        }

        template <>
        Object to_ruby<#{name}Proxy*>(#{name}Proxy* const &x) {
          if (!x) return Nil;
          return Data_Object<#{name}Proxy>(x, #{proxy_class_variable}, nullptr, nullptr);
        }
      END
    end

    def proxy_class_methods
      each_context_method.map do |ctx_method|
        return_type = capitalize(ctx_method.name)
        return_proxy_type = "#{return_type}Proxy"
        params = ctx_method.args.map(&:name).join(', ')

        if ctx_method.returns_vector?
          <<~END
            Object #{name}Proxy::#{ctx_method.name}(#{ctx_method.raw_args}) {
              std::vector<MySqlParser::#{return_type} *> vec = MySqlParser::#{name}::#{ctx_method.name}(#{params});
              return Array(vec.begin(), vec.end());
            }
          END
        else
          <<~END
            Object #{name}Proxy::#{ctx_method.name}(#{ctx_method.raw_args}) {
              auto proxy = static_cast<#{return_proxy_type}*>(MySqlParser::#{return_type}::#{ctx_method.name}(#{params}));
              return to_ruby(proxy);
            }
          END
        end
      end
    end

    def class_wrapper(module_var)
      @class_wrapper ||= begin
        lines = ["#{proxy_class_variable} = #{module_var}", ".define_class<#{name}Proxy, tree::ParseTree>(\"#{name}\")"]

        each_context_method do |ctx_method|
          lines << ".define_method(\"#{underscore(ctx_method.cpp_name)}\", &#{name}Proxy::#{ctx_method.cpp_name})"
        end

        lines[-1] << ';'
        lines
      end
    end

    private

    def define?(ctx_method)
      !(ctx_method.fetches_token? || ctx_method.rule? || ctx_method.meta? || ctx_method.constructor?)
    end

    def context_methods
      @methods ||= begin
        puts "Finding methods for #{name}"

        cpp_parser_source
          .scan(/^([^\n]+) MySqlParser::#{name}::([^\(]*)\(([^\)]*)\)/).flat_map do |return_type, mtd_name, args|
            ContextMethod.new(mtd_name, args, return_type, self)
          end
      end
    end
  end
end
