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

class MySqlVisitor : public MySqlParserBaseVisitor {
public:
  MySqlVisitor() { }
};

class MySqlVisitorProxy : public MySqlVisitor, public Rice::Director {
public:
  MySqlVisitorProxy(Object self) : Rice::Director(self) { }

  virtual antlrcpp::Any visitRoot(MySqlParser::RootContext *ctx) override {
    getSelf().call("visit_root", ctx);
    return Rice::Nil;
  }

  antlrcpp::Any default_visitRoot(MySqlParser::RootContext *ctx) {
    return MySqlVisitor::visitRoot(ctx);
  }
};

VALUE mysql_parser_parse(string file, MySqlVisitor* visitor) {
  ifstream stream;
  stream.open(file);

  ANTLRInputStream input(stream);
  MySqlLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  // Ruby segfaults if you delete this, no idea why.
  // Something must be holding a reference to it, but what?
  MySqlParser* parser = new MySqlParser(&tokens);
  MySqlParser::RootContext* tree = parser -> root();
  visitor -> visit(tree);
  stream.close();

  return Qnil;
}

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
    .define_method("visit_root", &MySqlVisitorProxy::default_visitRoot);

  rb_mMySqlParser
    .define_class<MySqlParser::RootContext>("RootContext")
    .define_method("rule_index", &MySqlParser::RootContext::getRuleIndex)
    .define_method("eof", &MySqlParser::RootContext::EOF);

  rb_mMySqlParser
    .define_class<Token>("Token")
    .define_method("text", &Token::getText);

  rb_mMySqlParser
    .define_class<tree::TerminalNode>("TerminalNode")
    .define_method("symbol", &tree::TerminalNode::getSymbol);
}
