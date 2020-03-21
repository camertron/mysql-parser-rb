#include "antlr4-runtime.h"
#include "MySqlParser.h"
#include "MySqlParserBaseVisitor.h"
#include "MySqlLexer.h"
#include "rice/Class.hpp"
#include "iostream"

using namespace std;
using namespace Rice;
using namespace antlr4;

class MyVisitor : public MySqlParserBaseVisitor {
  antlrcpp::Any visitSelectStarElement(MySqlParser::SelectStarElementContext *ctx) override {
    cout << "visitSelectStarElement was called!" << endl;
    return visitChildren(ctx);
  }
};

extern "C" {
  void Init_python_parser() {
    std::ifstream stream;
    stream.open("test.sql");

    ANTLRInputStream input(stream);
    MySqlLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    MySqlParser parser(&tokens);
    MySqlParser::RootContext* tree = parser.root();
    MyVisitor visitor;
    visitor.visitRoot(tree);

    // ImageVisitor visitor;
    // Scene scene = visitor.visitFile(tree);
    // scene.draw();
    // return 0;
  }
}

// int main(int argc, const char* argv[]) {
//   std::ifstream stream;
//   stream.open("test.sql");

//   ANTLRInputStream input(stream);
//   MySqlLexer lexer(&input);
//   CommonTokenStream tokens(&lexer);
//   MySqlParser parser(&tokens);
//   MySqlParser::RootContext* tree = parser.root();
//   MyVisitor visitor;
//   visitor.visitRoot(tree);

//   // ImageVisitor visitor;
//   // Scene scene = visitor.visitFile(tree);
//   // scene.draw();
//   return 0;
// }
