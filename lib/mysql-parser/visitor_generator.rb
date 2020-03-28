module MySqlParser
  class VisitorGenerator
    include StringHelpers

    attr_reader :visitor_methods

    def initialize(visitor_methods)
      @visitor_methods = visitor_methods
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
      vms = visitor_methods.flat_map do |visitor_method|
        context = "#{capitalize(visitor_method.sub(/\Avisit/, ''))}Context"

        [
          "  virtual antlrcpp::Any #{visitor_method}(MySqlParser::#{context} *ctx) override {",
          "    auto proxy = static_cast<#{context}Proxy*>(ctx);",
          "    return getSelf().call(\"visit_#{underscore(visitor_method)}\", proxy);",
          "  }\n",
        ]
      end

      <<~END
        class MySqlVisitorProxy : public MySqlVisitor, public Rice::Director {
        public:
          MySqlVisitorProxy(Object self) : Rice::Director(self) { }

        #{vms.join("\n")}
        };
      END
    end
  end
end
