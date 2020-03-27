require 'mysql-parser'
require 'pry-byebug'

task :antlr do
  system(<<~END)
    java -jar ~/.m2/repository/org/antlr/antlr4/4.7.3-SNAPSHOT/antlr4-4.7.3-SNAPSHOT-complete.jar \
      -o ./ext/mysql-parser/ \
      -Dlanguage=Cpp \
      -visitor \
      MySqlLexer.g4 MySqlParser.g4
  END
end

task :generate do
  generator = MySqlParser::Generator.new(
    File.read('ext/mysql-parser/MySqlParser.cpp'),
    File.read('ext/mysql-parser/MysqlParserBaseVisitor.h')
  )

  File.write('ext/mysql-parser/mysql_parser.cpp', generator.generate)
end
