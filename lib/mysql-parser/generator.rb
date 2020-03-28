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

        #{proxy_class_headers}

        #{proxy_class_declarations}

        #{conversions}

        #{proxy_class_methods}

        #{visitor_generator.visitor}

        #{visitor_generator.visitor_proxy}

        #{parse_function}

        #{init_function}
      END
    end

    private

    def proxy_class_headers
      @proxy_class_headers ||= contexts
        .map(&:proxy_class_header)
        .join("\n")
    end

    def proxy_class_declarations
      @proxy_class_declarations ||= contexts
        .map { |ctx| "Class #{ctx.proxy_class_variable}" }
        .concat(['Class rb_cParseTree'])
        .join("\n")
    end

    def conversions
      @conversions ||= begin
        context_conversions = contexts.map(&:conversions).join("\n")

        <<~END
          template <>
          Object to_ruby<tree::ParseTree*>(tree::ParseTree* const &x) {
            if (!x) return Nil;
            return Data_Object<tree::ParseTree>(x, rb_cParseTree, nullptr, nullptr);
          }

          #{context_conversions}
        END
      end
    end

    def proxy_class_methods
      @proxy_class_methods ||= contexts
        .flat_map(&:proxy_class_methods)
        .join("\n")
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
          CommonTokenStream tokens(&lexer);
          MySqlParser parser(&tokens);
          visitor -> visit(parser.root());
          stream.close();

          return Qnil;
        }
      END
    end

    def init_function
      <<~END
        extern "C"
        void Init_mysql_parser() {
          Module rb_mMySqlParser = define_module("MySqlParser");

          rb_mMySqlParser
            .define_class("Parser")
            .define_method("parse", &mysql_parser_parse);

          rb_cParseTree = rb_mMySqlParser
            .define_class<tree::ParseTree>("ParseTree");

          rb_mMySqlParser
            .define_class<MySqlVisitor>("MySqlVisitor")
            .define_director<MySqlVisitorProxy>()
            .define_constructor(Constructor<MySqlVisitorProxy, Object>())
            .define_method("visit", &MySqlVisitorProxy::ruby_visit)
            .define_method("visit_children", &MySqlVisitorProxy::ruby_visitChildren);

        #{class_wrappers_str('  ')}
        }
      END
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

        # .select { |ctx| %w(RootContext SqlStatementsContext SqlStatementContext).include?(ctx) }
    end

    def visitor_methods
      @visitor_methods ||= cpp_visitor_source
        .scan(/visit[A-Z][^\(\s]*/)
        .flatten
        .uniq
        # .select { |mtd| %w(visitRoot visitSqlStatements visitSqlStatement).include?(mtd) }
    end

    def visitor_generator
      @visitor_generator ||= VisitorGenerator.new(visitor_methods)
    end
  end
end
