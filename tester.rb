require './mysql_parser'

class MyVisitor < MySqlParser::MySqlVisitor
  def visit_root(ctx)
    puts 'visit_root called from rubyland!'
    puts ctx.eof.symbol.text
  end
end

visitor = MyVisitor.new
MySqlParser::Parser.new.parse('./test.sql', visitor)
