require './mysql_parser'
require 'pry-byebug'

class MyVisitor < MySqlParser::MySqlVisitor
  def visit_root(ctx)
    puts 'visit_root called from rubyland!'
    # puts ctx.sql_statements.sql_statement.inspect
    visit_children(ctx)
  end

  # def visit_sql_statements(ctx)
  # #   puts 'visit_sql_statements called from rubyland!'
  #   visit_children(ctx)
  # end

  # def visit_select_spec(ctx)
  #   puts "visit_select_spec called in ruby"
  #   binding.pry
  # end
end

visitor = MyVisitor.new
MySqlParser::Parser.new.parse('./test.sql', visitor)
puts 'done!'
