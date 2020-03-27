#include "iostream"

#include "antlr4-runtime.h"

#include "MySqlParser.h"
#include "MySqlParserBaseVisitor.h"
#include "MySqlLexer.h"

#include "rice/Array.hpp"
#include "rice/Class.hpp"
#include "rice/Constructor.hpp"
#include "rice/Director.hpp"

using namespace std;
using namespace Rice;
using namespace antlr4;

class RootContextProxy : public MySqlParser::RootContext {
public:
  Object sqlStatements();
};

class SqlStatementsContextProxy : public MySqlParser::SqlStatementsContext {
public:
  Object sqlStatement();
  Object emptyStatement();
};

class MySqlVisitor : public MySqlParserBaseVisitor {
public:
  MySqlVisitor() { }
};

Class rb_cParseTree;

Class rb_cRootContext;
Class rb_cSqlStatementsContext;
Class rb_cSqlStatementContext;
Class rb_cEmptyStatementContext;

template <>
Object to_ruby<tree::ParseTree*>(tree::ParseTree* const &x) {
  if (!x) return Nil;
  return Data_Object<tree::ParseTree>(x, rb_cParseTree, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::RootContext*>(MySqlParser::RootContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::RootContext>(x, rb_cRootContext, nullptr, nullptr);
}

template <>
Object to_ruby<RootContextProxy*>(RootContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<RootContextProxy>(x, rb_cRootContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SqlStatementsContext*>(MySqlParser::SqlStatementsContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SqlStatementsContext>(x, rb_cSqlStatementsContext, nullptr, nullptr);
}

template <>
Object to_ruby<SqlStatementsContextProxy*>(SqlStatementsContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SqlStatementsContextProxy>(x, rb_cSqlStatementsContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::SqlStatementContext*>(MySqlParser::SqlStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::SqlStatementContext>(x, rb_cSqlStatementContext, nullptr, nullptr);
}

template <>
Object to_ruby<MySqlParser::EmptyStatementContext*>(MySqlParser::EmptyStatementContext* const &x) {
  if (!x) return Nil;
  return Data_Object<MySqlParser::EmptyStatementContext>(x, rb_cEmptyStatementContext, nullptr, nullptr);
}

Object RootContextProxy::sqlStatements() {
  auto proxy = static_cast<SqlStatementsContextProxy*>(MySqlParser::RootContext::sqlStatements());
  return to_ruby(proxy);
}

Object SqlStatementsContextProxy::sqlStatement() {
  std::vector<MySqlParser::SqlStatementContext *> vec = MySqlParser::SqlStatementsContext::sqlStatement();
  return Array(vec.begin(), vec.end());
}

Object SqlStatementsContextProxy::emptyStatement() {
  std::vector<MySqlParser::EmptyStatementContext *> vec = MySqlParser::SqlStatementsContext::emptyStatement();
  return Array(vec.begin(), vec.end());
}

class MySqlVisitorProxy : public MySqlVisitor, public Rice::Director {
public:
  MySqlVisitorProxy(Object self) : Rice::Director(self) { }

  Object ruby_visitChildren(tree::ParseTree *node) {
    MySqlVisitor::visitChildren(node);
    return Rice::Nil;
  }

  virtual antlrcpp::Any visitRoot(MySqlParser::RootContext *ctx) override {
    auto proxy = static_cast<RootContextProxy*>(ctx);
    return getSelf().call("visit_root", proxy);
  }

  virtual antlrcpp::Any visitSqlStatements(MySqlParser::SqlStatementsContext *ctx) override {
    auto proxy = static_cast<SqlStatementsContextProxy*>(ctx);
    return getSelf().call("visit_sql_statements", proxy);
  }
};

VALUE mysql_parser_parse(string file, MySqlVisitor* visitor) {
  ifstream stream;
  stream.open(file);

  ANTLRInputStream input(stream);
  MySqlLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  MySqlParser parser(&tokens);
  visitor -> visit(parser.root());
  stream.close();

  return Qnil;
}

extern "C"
void Init_mysql_parser() {
  Module rb_mMySqlParser = define_module("MySqlParser");

  rb_mMySqlParser
    .define_class<Token>("Token")
    .define_method("text", &Token::getText);

  rb_mMySqlParser
    .define_class<tree::TerminalNode>("TerminalNode")
    .define_method("symbol", &tree::TerminalNode::getSymbol);

  rb_cParseTree = rb_mMySqlParser
    .define_class<tree::ParseTree>("ParseTree");

  rb_mMySqlParser
    .define_class("Parser")
    .define_method("parse", &mysql_parser_parse);

  rb_mMySqlParser
    .define_class<MySqlVisitor>("MySqlVisitor")
    .define_director<MySqlVisitorProxy>()
    .define_constructor(Constructor<MySqlVisitorProxy, Object>())
    .define_method("visit_children", &MySqlVisitorProxy::ruby_visitChildren);

  rb_cRootContext = rb_mMySqlParser
    .define_class<RootContextProxy, tree::ParseTree>("RootContext")
    .define_method("sql_statements", &RootContextProxy::sqlStatements);
    // .define_method("eof", &RootContextProxy::EOF);
    // .define_method("rule_index", &RootContextProxy::getRuleIndex)

  rb_cSqlStatementsContext = rb_mMySqlParser
    .define_class<SqlStatementsContextProxy, tree::ParseTree>("SqlStatementsContext")
    .define_method("sql_statement", &SqlStatementsContextProxy::sqlStatement)
    .define_method("empty_statement", &SqlStatementsContextProxy::emptyStatement);

  rb_cSqlStatementContext = rb_mMySqlParser
    .define_class<MySqlParser::SqlStatementContext>("SqlStatementContext");

  rb_cEmptyStatementContext = rb_mMySqlParser
    .define_class<MySqlParser::EmptyStatementContext>("EmptyStatementContext");
}
