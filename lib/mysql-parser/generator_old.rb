module MySqlParser
  class Generator
    include StringHelpers

    attr_reader :cpp_parser_source, :cpp_visitor_source

    def initialize(cpp_parser_source, cpp_visitor_source)
      @cpp_parser_source = cpp_parser_source
      @cpp_visitor_source = cpp_visitor_source
    end

    def generate
      <<~END
        #include "iostream"

        #include "antlr4-runtime.h"

        #include "MySqlParser.h"
        #include "MySqlParserBaseVisitor.h"
        #include "MySqlLexer.h"

        #include "rice/Class.hpp"
        #include "rice/Constructor.hpp"
        #include "rice/Director.hpp"

        using namespace std;
        using namespace Rice;
        using namespace antlr4;

        #{visitor}

        #{visitor_proxy}

        #{parse_function}

        #{init_function}
      END
    end

    private

    def init_function
      <<~END
        extern "C"
        void Init_mysql_parser() {
          Module rb_mMySqlParser = define_module("MySqlParser");

          rb_mMySqlParser
            .define_class("Parser")
            .define_method("parse", &mysql_parser_parse);

          rb_mMySqlParser
            .define_class<MySqlVisitor>("MySqlVisitor")
            .define_director<MySqlVisitorProxy>()
            .define_constructor(Constructor<MySqlVisitorProxy, Object>())
        #{visitor_proxy_methods('    ').join("\n")};

        #{class_wrappers_str('  ')}
        }
      END
    end

    def parse_function
      @parse_function ||= <<~END
        VALUE mysql_parser_parse(string file, MySqlVisitor* visitor) {
          ifstream stream;
          stream.open(file);

          ANTLRInputStream input(stream);
          MySqlLexer lexer(&input);
          // these both need to be allocated on the heap or Ruby segfaults
          // when the program exits
          CommonTokenStream* tokens = new CommonTokenStream(&lexer);
          MySqlParser* parser = new MySqlParser(tokens);
          visitor -> visit(parser -> root());
          stream.close();

          return Qnil;
        }
      END
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
          "    getSelf().call(\"#{underscore(visitor_method)}\", ctx);",
          "    return Rice::Nil;",
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

        #{vms.join("\n")}
        };
      END
    end

    def visitor_proxy_methods(indent)
      @visitor_proxy_methods ||= visitor_methods.map do |visitor_method|
        "#{indent}.define_method(\"#{underscore(visitor_method)}\", &MySqlVisitorProxy::default_#{visitor_method})"
      end
    end

    def class_wrappers_str(indent)
      class_wrappers.map do |cw|
        ["#{indent}#{cw[0]}", *cw[1..-1].map { |line| "#{indent}  #{line}" }].join("\n")
      end.join("\n\n")
    end

    def class_wrappers
      @class_wrappers ||= contexts.map do |ctx|
        ctx.class_wrapper('rb_mMySqlParser')
      end
    end

    def contexts
      @contexts ||= cpp_parser_source
        .scan(/MySqlParser::([^\s:\(\)_]+Context)/)
        .flatten
        .uniq
        .map { |name| Context.new(name, cpp_parser_source) }
    end

    def visitor_methods
      @visitor_methods ||= cpp_visitor_source
        .scan(/visit[A-Z][^\(\s]*/)
        .flatten
        .uniq
    end
  end
end
