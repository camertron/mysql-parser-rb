require 'mkmf-rice'

have_library('stdc++')

$CFLAGS << ' -std=c++14'

antlr_include_paths = [
  '/',
  '/atn',
  '/dfa',
  '/misc',
  '/support',
  '/tree',
  '/tree/pattern',
  '/tree/xpath'
]

antlr_src_globs = [
  "/*.cpp",
  "/atn/*.cpp",
  "/dfa/*.cpp",
  "/misc/*.cpp",
  "/support/*.cpp",
  "/tree/*.cpp",
  "/tree/pattern/*.cpp",
  "/tree/xpath/*.cpp"
]

$srcs = []

antlr_include_paths.each do |include_path|
  $INCFLAGS << " -I$(srcdir)/antlr4-upstream/runtime/Cpp/runtime/src#{include_path}"
end

antlr_src_globs.each do |src_glob|
  Dir.chdir('ext/python-parser') do
    Dir.glob("antlr4-upstream/runtime/Cpp/runtime/src#{src_glob}").each do |path|
      $srcs << "$(srcdir)/#{path}"
    end
  end
end

# $INCFLAGS << " -I$(srcdir)/antlr4-upstream/runtime/Cpp/runtime/src"
# $VPATH << "$(srcdir)/antlr4-upstream/runtime/Cpp/runtime/src"

create_makefile('python_parser')
