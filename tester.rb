require './mysql_parser'
require 'pry-byebug'
require 'benchmark/ips'

class MyVisitor < MySqlParser::MySqlVisitor
  def visit_root(ctx)
    # puts 'visit_root called from rubyland!'
    # puts ctx.sql_statements.inspect
    visit_children(ctx)
  end

  def visit_sql_statements(ctx)
    # puts 'visit_sql_statements called from rubyland!'
    # puts ctx.sql_statement.inspect
    visit_children(ctx)
  end

  def visit_sql_statement(ctx)
    # puts "visit_sql_statement called from rubyland!"
    visit_children(ctx)
  end
end

visitor = MyVisitor.new
parser = MySqlParser::Parser.new

parser.parse('./test.sql', visitor)

Benchmark.ips do |x|
  x.report do
    parser.parse('./test.sql', visitor)
  end
end
