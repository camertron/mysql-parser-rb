module MySqlParser
  class VisitorGenerator
    VISITOR_METHOD_BLACKLIST = %w(visit visitChildren).freeze

    include StringHelpers

    attr_reader :visitor_methods

    def initialize(visitor_methods)
      @visitor_methods = visitor_methods
    end

    def each_visitor_method
      return to_enum(__method__) unless block_given?

      visitor_methods.each do |visitor_method|
        yield visitor_method unless VISITOR_METHOD_BLACKLIST.include?(visitor_method)
      end
    end

    def visitor
      @visitor ||= <<~END
        class MySqlVisitor : public MySqlParserBaseVisitor {
        public:
          MySqlVisitor() { }
        };
      END
    end

    def visitor_proxy
      vms = each_visitor_method.flat_map do |visitor_method|
        context = "#{capitalize(visitor_method.sub(/\Avisit/, ''))}Context"

        [
          "  virtual antlrcpp::Any #{visitor_method}(MySqlParser::#{context} *ctx) override {",
          "    auto proxy = static_cast<#{context}Proxy*>(ctx);",
          "    return getSelf().call(\"#{underscore(visitor_method)}\", proxy);",
          "  }\n",
          "  antlrcpp::Any default_#{visitor_method}(MySqlParser::#{context} *ctx) {",
          "    return MySqlVisitor::#{visitor_method}(ctx);",
          "  }\n"
        ]
      end

      <<~END
        class MySqlVisitorProxy : public MySqlVisitor, public Rice::Director {
        public:
          MySqlVisitorProxy(Object self) : Rice::Director(self) { }

          Object ruby_visit(tree::ParseTree *node) {
            MySqlVisitor::visit(node);
            return Rice::Nil;
          }

          Object ruby_visitChildren(tree::ParseTree *node) {
            MySqlVisitor::visitChildren(node);
            return Rice::Nil;
          }

        #{vms.join("\n")}
        };
      END
    end

    def visitor_proxy_methods(indent)
      @visitor_proxy_methods ||= each_visitor_method.map do |visitor_method|
        "#{indent}.define_method(\"#{underscore(visitor_method)}\", &MySqlVisitorProxy::default_#{visitor_method})"
      end
    end
  end
end
