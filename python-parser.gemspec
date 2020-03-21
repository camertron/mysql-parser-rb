$:.unshift File.join(File.dirname(__FILE__), 'lib')
require 'python-parser/version'

Gem::Specification.new do |s|
  s.name     = 'python-parser'
  s.version  = ::PythonParser::VERSION
  s.authors  = ['Cameron Dutro']
  s.email    = ['camertron@gmail.com']
  s.homepage = 'http://github.com/camertron/python-parser'

  s.description = s.summary = 'A Python source code parser for Ruby.'

  s.platform = Gem::Platform::RUBY
  s.has_rdoc = true

  s.require_path = 'lib'
  s.files = Dir['{lib,spec}/**/*', 'Gemfile', 'README.md', 'Rakefile', 'python-parser.gemspec']
end
