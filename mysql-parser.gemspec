$:.unshift File.join(File.dirname(__FILE__), 'lib')
require 'mysql-parser/version'

Gem::Specification.new do |s|
  s.name     = 'python-parser'
  s.version  = ::MySqlParser::VERSION
  s.authors  = ['Cameron Dutro']
  s.email    = ['camertron@gmail.com']
  s.homepage = 'http://github.com/camertron/python-parser'

  s.description = s.summary = 'A MySQL query parser for Ruby.'

  s.platform = Gem::Platform::RUBY
  s.has_rdoc = true

  s.add_dependency 'rice', '~> 2.0'

  s.require_path = 'lib'
  s.files = Dir['{lib,spec}/**/*', 'Gemfile', 'README.md', 'Rakefile', 'mysql-parser.gemspec']
end
