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

    def class_wrapper(module_var)
      @class_wrapper ||= begin
        lines = [module_var, ".define_class<MySqlParser::#{name}>(\"#{name}\")"]

        each_context_method do |ctx_method|
          lines << ".define_method(\"#{underscore(ctx_method.name)}\", &MySqlParser::#{name}::#{ctx_method.name})"
        end

        lines[-1] << ';'
        lines
      end
    end

    private

    def define?(ctx_method)
      !(ctx_method.fetches_token? || ctx_method.rule? || ctx_method.constructor?)
    end

    def context_methods
      @methods ||= cpp_parser_source
        .scan(/MySqlParser::#{name}::([^\(]+)\(([^\)]+)\)/).flat_map do |name, args|
          ContextMethod.new(name, args, self)
        end
    end
  end
end
