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

class ContextProxy {
public:
  ContextProxy(tree::ParseTree* orig) {
    this -> orig = orig;
  }

  tree::ParseTree* getOriginal();

protected:
  tree::ParseTree* orig;
};

class RootContextProxy : public ContextProxy {
public:
  RootContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object sqlStatements();
};

class SqlStatementsContextProxy : public ContextProxy {
public:
  SqlStatementsContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
  Object sqlStatement();
};

class SqlStatementContextProxy : public ContextProxy {
public:
  SqlStatementContextProxy(tree::ParseTree* ctx) : ContextProxy(ctx) {};
};

Class rb_cParseTree;

Class rb_cRootContext;
Class rb_cSqlStatementsContext;
Class rb_cSqlStatementContext;

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
Object to_ruby<SqlStatementContextProxy*>(SqlStatementContextProxy* const &x) {
  if (!x) return Nil;
  return Data_Object<SqlStatementContextProxy>(x, rb_cSqlStatementContext, nullptr, nullptr);
}

tree::ParseTree* ContextProxy::getOriginal() {
  return this -> orig;
}

Object RootContextProxy::sqlStatements() {
  SqlStatementsContextProxy proxy(((MySqlParser::RootContext*)orig) -> sqlStatements());
  return to_ruby(proxy);
}

Object SqlStatementsContextProxy::sqlStatement() {
  std::vector<MySqlParser::SqlStatementContext *> vec = ((MySqlParser::SqlStatementsContext*)orig) -> sqlStatement();
  return Array(vec.begin(), vec.end());
}

class MySqlVisitor : public MySqlParserBaseVisitor {
public:
  MySqlVisitor() { }
};

class MySqlVisitorProxy : public MySqlVisitor, public Rice::Director {
public:
  MySqlVisitorProxy(Object self) : Rice::Director(self) { }

  Object ruby_visit(ContextProxy* proxy) {
    cout << "called ruby_visit" << endl;
    visit(proxy -> getOriginal());
    return Rice::Nil;
  }

  Object ruby_visitChildren(ContextProxy* proxy) {
    cout << "called ruby_visitChildren" << endl;
    visitChildren(proxy -> getOriginal());
    return Rice::Nil;
  }

  virtual antlrcpp::Any visitRoot(MySqlParser::RootContext* ctx) override {
    cout << "called visitRoot" << endl;
    RootContextProxy proxy(ctx);
    return getSelf().call("visit_root", &proxy);
  }

  Object default_visitRoot(RootContextProxy* ctx) {
    cout << "called default_visitRoot" << endl;
    return ruby_visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSqlStatements(MySqlParser::SqlStatementsContext* ctx) override {
    cout << "called visitSqlStatements" << endl;
    SqlStatementsContextProxy proxy(ctx);
    cout << "visitSqlStatements: cast successful" << endl;
    auto retval = getSelf().call("visit_sql_statements", &proxy);
    cout << "visitSqlStatements: ruby call successful" << endl;
    return retval;
  }

  Object default_visitSqlStatements(SqlStatementsContextProxy* ctx) {
    cout << "called default_visitSqlStatements" << endl;
    return ruby_visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSqlStatement(MySqlParser::SqlStatementContext* ctx) override {
    cout << "called visitSqlStatement" << endl;
    SqlStatementContextProxy proxy(ctx);
    return getSelf().call("visit_sql_statement", &proxy);
  }

  Object default_visitSqlStatement(SqlStatementContextProxy* ctx) {
    cout << "called default_visitSqlStatement" << endl;
    return ruby_visitChildren(ctx);
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
    .define_method("visit", &MySqlVisitorProxy::ruby_visit)
    .define_method("visit_children", &MySqlVisitorProxy::ruby_visitChildren)
    .define_method("visit_root", &MySqlVisitorProxy::default_visitRoot)
    .define_method("visit_sql_statements", &MySqlVisitorProxy::default_visitSqlStatements)
    .define_method("visit_sql_statement", &MySqlVisitorProxy::default_visitSqlStatement);

  rb_mMySqlParser
    .define_class<ContextProxy>("Context");

  rb_cRootContext = rb_mMySqlParser
    .define_class<RootContextProxy, ContextProxy>("RootContext")
    .define_method("sql_statements", &RootContextProxy::sqlStatements);

  rb_cSqlStatementsContext = rb_mMySqlParser
    .define_class<SqlStatementsContextProxy, ContextProxy>("SqlStatementsContext")
    .define_method("sql_statement", &SqlStatementsContextProxy::sqlStatement);

  rb_cSqlStatementContext = rb_mMySqlParser
    .define_class<SqlStatementContextProxy, ContextProxy>("SqlStatementContext");
}
