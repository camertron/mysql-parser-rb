task :antlr do
  system(<<~END)
    java -jar ~/.m2/repository/org/antlr/antlr4/4.7.3-SNAPSHOT/antlr4-4.7.3-SNAPSHOT-complete.jar \
      -o ./ext/mysql-parser/ \
      -Dlanguage=Cpp \
      -visitor \
      MySqlLexer.g4 MySqlParser.g4
  END
end
