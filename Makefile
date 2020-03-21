
SHELL = /bin/sh

# V=0 quiet, V=1 verbose.  other values don't work.
V = 0
Q1 = $(V:1=)
Q = $(Q1:0=@)
ECHO1 = $(V:1=@ :)
ECHO = $(ECHO1:0=@ echo)
NULLCMD = :

#### Start of system configuration section. ####

srcdir = ext/python-parser
topdir = /Users/cameron/.rbenv/versions/2.5.6/include/ruby-2.5.0
hdrdir = $(topdir)
arch_hdrdir = /Users/cameron/.rbenv/versions/2.5.6/include/ruby-2.5.0/x86_64-darwin17
PATH_SEPARATOR = :
VPATH = $(srcdir):$(arch_hdrdir)/ruby:$(hdrdir)/ruby

prefix = $(DESTDIR)/Users/cameron/.rbenv/versions/2.5.6

rubysitearchprefix = $(rubylibprefix)/$(sitearch)

rubyarchprefix = $(rubylibprefix)/$(arch)

rubylibprefix = $(libdir)/$(RUBY_BASE_NAME)

exec_prefix = $(prefix)

vendorarchhdrdir = $(vendorhdrdir)/$(sitearch)

sitearchhdrdir = $(sitehdrdir)/$(sitearch)

rubyarchhdrdir = $(rubyhdrdir)/$(arch)

vendorhdrdir = $(rubyhdrdir)/vendor_ruby

sitehdrdir = $(rubyhdrdir)/site_ruby

rubyhdrdir = $(includedir)/$(RUBY_VERSION_NAME)

vendorarchdir = $(vendorlibdir)/$(sitearch)

vendorlibdir = $(vendordir)/$(ruby_version)

vendordir = $(rubylibprefix)/vendor_ruby

sitearchdir = $(sitelibdir)/$(sitearch)

sitelibdir = $(sitedir)/$(ruby_version)

sitedir = $(rubylibprefix)/site_ruby

rubyarchdir = $(rubylibdir)/$(arch)

rubylibdir = $(rubylibprefix)/$(ruby_version)

sitearchincludedir = $(includedir)/$(sitearch)

archincludedir = $(includedir)/$(arch)

sitearchlibdir = $(libdir)/$(sitearch)

archlibdir = $(libdir)/$(arch)

ridir = $(datarootdir)/$(RI_BASE_NAME)

mandir = $(datarootdir)/man

localedir = $(datarootdir)/locale

libdir = $(exec_prefix)/lib

psdir = $(docdir)

pdfdir = $(docdir)

dvidir = $(docdir)

htmldir = $(docdir)

infodir = $(datarootdir)/info

docdir = $(datarootdir)/doc/$(PACKAGE)

oldincludedir = $(SDKROOT)/usr/include

includedir = $(prefix)/include

runstatedir = $(localstatedir)/run

localstatedir = $(prefix)/var

sharedstatedir = $(prefix)/com

sysconfdir = $(prefix)/etc

datadir = $(datarootdir)

datarootdir = $(prefix)/share

libexecdir = $(exec_prefix)/libexec

sbindir = $(exec_prefix)/sbin

bindir = $(exec_prefix)/bin

archdir = $(rubyarchdir)



CC = clang
CXX = clang++
LIBRUBY = $(LIBRUBY_SO)
LIBRUBY_A = lib$(RUBY_SO_NAME)-static.a
LIBRUBYARG_SHARED = -l$(RUBY_SO_NAME)
LIBRUBYARG_STATIC = -lruby.2.5.6-static -framework Foundation
empty =
OUTFLAG = -o $(empty)
COUTFLAG = -o $(empty)
CSRCFLAG = $(empty)

RUBY_EXTCONF_H = 
cflags   = $(optflags) $(debugflags) $(warnflags)
cxxflags = $(optflags) $(debugflags) $(warnflags)
optflags = -O3
debugflags = -ggdb3
warnflags = -Wall -Wextra -Wno-unused-parameter -Wno-parentheses -Wno-long-long -Wno-missing-field-initializers -Wno-tautological-compare -Wno-parentheses-equality -Wno-constant-logical-operand -Wno-self-assign -Wunused-variable -Wimplicit-int -Wpointer-arith -Wwrite-strings -Wdeclaration-after-statement -Wshorten-64-to-32 -Wimplicit-function-declaration -Wdivision-by-zero -Wdeprecated-declarations -Wextra-tokens
CCDLFLAGS = -fno-common
CFLAGS   = $(CCDLFLAGS)  -O3 -Wno-error=shorten-64-to-32  -fno-common -pipe -std=c++14 $(ARCH_FLAG)
INCFLAGS = -I. -I$(arch_hdrdir) -I$(hdrdir)/ruby/backward -I$(hdrdir) -I$(srcdir) -I$(srcdir)/antlr4-upstream/runtime/Cpp/runtime/src/ -I$(srcdir)/antlr4-upstream/runtime/Cpp/runtime/src/atn -I$(srcdir)/antlr4-upstream/runtime/Cpp/runtime/src/dfa -I$(srcdir)/antlr4-upstream/runtime/Cpp/runtime/src/misc -I$(srcdir)/antlr4-upstream/runtime/Cpp/runtime/src/support -I$(srcdir)/antlr4-upstream/runtime/Cpp/runtime/src/tree -I$(srcdir)/antlr4-upstream/runtime/Cpp/runtime/src/tree/pattern -I$(srcdir)/antlr4-upstream/runtime/Cpp/runtime/src/tree/xpath
DEFS     = 
CPPFLAGS =  -I/Users/cameron/.rbenv/versions/2.5.6/include  -D_XOPEN_SOURCE -D_DARWIN_C_SOURCE -D_DARWIN_UNLIMITED_SELECT -D_REENTRANT $(DEFS) $(cppflags) -arch x86_64 -I/Users/cameron/.rbenv/versions/2.5.6/lib/ruby/gems/2.5.0/gems/rice-2.2.0/ruby/lib/include
CXXFLAGS = $(CFLAGS)  -Wall -g
ldflags  = -L. -L/Users/cameron/.rbenv/versions/2.5.6/lib  -fstack-protector -L/usr/local/lib  -L/Users/cameron/.rbenv/versions/2.5.6/lib/ruby/gems/2.5.0/gems/rice-2.2.0/ruby/lib/lib -lrice
dldflags = -L/Users/cameron/.rbenv/versions/2.5.6/lib  -Wl,-undefined,dynamic_lookup -Wl,-multiply_defined,suppress 
ARCH_FLAG = 
DLDFLAGS = $(ldflags) $(dldflags) $(ARCH_FLAG)
LDSHARED = g++ -dynamic -bundle
LDSHAREDXX = $(CXX) -dynamic -bundle
AR = libtool -static
EXEEXT = 


RUBY_INSTALL_NAME = $(RUBY_BASE_NAME)

RUBY_SO_NAME = ruby.2.5.6

RUBYW_INSTALL_NAME = 

RUBY_VERSION_NAME = $(RUBY_BASE_NAME)-$(ruby_version)

RUBYW_BASE_NAME = rubyw

RUBY_BASE_NAME = ruby


arch = x86_64-darwin17
sitearch = $(arch)
ruby_version = 2.5.0
ruby = $(bindir)/$(RUBY_BASE_NAME)
RUBY = $(ruby)
ruby_headers = $(hdrdir)/ruby.h $(hdrdir)/ruby/backward.h $(hdrdir)/ruby/ruby.h $(hdrdir)/ruby/defines.h $(hdrdir)/ruby/missing.h $(hdrdir)/ruby/intern.h $(hdrdir)/ruby/st.h $(hdrdir)/ruby/subst.h $(arch_hdrdir)/ruby/config.h

RM = rm -f
RM_RF = $(RUBY) -run -e rm -- -rf
RMDIRS = rmdir -p
MAKEDIRS = /usr/local/bin/gmkdir -p
INSTALL = /usr/local/bin/ginstall -c
INSTALL_PROG = $(INSTALL) -m 0755
INSTALL_DATA = $(INSTALL) -m 644
COPY = cp
TOUCH = exit >

#### End of system configuration section. ####

preload = 


CXX = g++
libpath = . $(libdir)
LIBPATH =  -L. -L$(libdir)
DEFFILE = 

CLEANFILES = mkmf.log
DISTCLEANFILES = 
DISTCLEANDIRS = 

extout = 
extout_prefix = 
target_prefix = 
LOCAL_LIBS = 
LIBS = -lstdc++ -lruby.2.5.6 -lpthread -lgmp -ldl -lobjc 
ORIG_SRCS = MySqlLexer.cpp MySqlParser.cpp MySqlParserBaseListener.cpp MySqlParserBaseVisitor.cpp MySqlParserListener.cpp MySqlParserVisitor.cpp python_parser.cpp
SRCS = $(ORIG_SRCS) Exceptions.cpp DiagnosticErrorListener.cpp FailedPredicateException.cpp ConsoleErrorListener.cpp UnbufferedCharStream.cpp TokenStream.cpp UnbufferedTokenStream.cpp BaseErrorListener.cpp RuntimeMetaData.cpp InputMismatchException.cpp RuleContextWithAltNum.cpp Vocabulary.cpp ListTokenSource.cpp ANTLRErrorListener.cpp CommonTokenFactory.cpp TokenStreamRewriter.cpp CharStream.cpp ANTLRFileStream.cpp Lexer.cpp ProxyErrorListener.cpp ANTLRErrorStrategy.cpp RuleContext.cpp BufferedTokenStream.cpp LexerInterpreter.cpp Recognizer.cpp IntStream.cpp InterpreterRuleContext.cpp ParserInterpreter.cpp TokenSource.cpp BailErrorStrategy.cpp CommonTokenStream.cpp DefaultErrorStrategy.cpp CommonToken.cpp NoViableAltException.cpp ParserRuleContext.cpp RecognitionException.cpp Parser.cpp ANTLRInputStream.cpp Token.cpp LexerNoViableAltException.cpp WritableToken.cpp BlockStartState.cpp StarBlockStartState.cpp BlockEndState.cpp Transition.cpp EmptyPredictionContext.cpp ParseInfo.cpp ATNConfig.cpp LexerTypeAction.cpp AtomTransition.cpp AmbiguityInfo.cpp ATNSimulator.cpp LexerIndexedCustomAction.cpp RuleTransition.cpp TokensStartState.cpp PredicateTransition.cpp SingletonPredictionContext.cpp LexerMoreAction.cpp ATNDeserializationOptions.cpp LoopEndState.cpp LexerActionExecutor.cpp LexerATNSimulator.cpp SetTransition.cpp LexerModeAction.cpp NotSetTransition.cpp ProfilingATNSimulator.cpp LexerATNConfig.cpp DecisionInfo.cpp ATNState.cpp ATNSerializer.cpp ArrayPredictionContext.cpp PredictionMode.cpp LookaheadEventInfo.cpp ATN.cpp SemanticContext.cpp RuleStopState.cpp OrderedATNConfigSet.cpp RangeTransition.cpp ATNDeserializer.cpp PlusBlockStartState.cpp WildcardTransition.cpp ActionTransition.cpp ParserATNSimulator.cpp DecisionState.cpp RuleStartState.cpp ErrorInfo.cpp StarLoopbackState.cpp BasicState.cpp AbstractPredicateTransition.cpp PredictionContext.cpp LexerAction.cpp LL1Analyzer.cpp EpsilonTransition.cpp LexerCustomAction.cpp PrecedencePredicateTransition.cpp PlusLoopbackState.cpp LexerPopModeAction.cpp PredicateEvalInfo.cpp LexerSkipAction.cpp ContextSensitivityInfo.cpp ATNConfigSet.cpp LexerChannelAction.cpp BasicBlockStartState.cpp DecisionEventInfo.cpp LexerPushModeAction.cpp StarLoopEntryState.cpp DFAState.cpp DFASerializer.cpp DFA.cpp LexerDFASerializer.cpp InterpreterDataReader.cpp IntervalSet.cpp Predicate.cpp MurmurHash.cpp Interval.cpp CPPUtils.cpp Any.cpp StringUtils.cpp Arrays.cpp guid.cpp TerminalNodeImpl.cpp ErrorNode.cpp Trees.cpp ParseTreeListener.cpp ParseTree.cpp ParseTreeVisitor.cpp ErrorNodeImpl.cpp ParseTreeWalker.cpp IterativeParseTreeWalker.cpp TerminalNode.cpp RuleTagToken.cpp ParseTreeMatch.cpp TokenTagToken.cpp Chunk.cpp ParseTreePatternMatcher.cpp TextChunk.cpp TagChunk.cpp ParseTreePattern.cpp XPathLexerErrorListener.cpp XPathRuleElement.cpp XPathElement.cpp XPathWildcardAnywhereElement.cpp XPathRuleAnywhereElement.cpp XPathWildcardElement.cpp XPathLexer.cpp XPath.cpp XPathTokenAnywhereElement.cpp XPathTokenElement.cpp
OBJS = Exceptions.o DiagnosticErrorListener.o FailedPredicateException.o ConsoleErrorListener.o UnbufferedCharStream.o TokenStream.o UnbufferedTokenStream.o BaseErrorListener.o RuntimeMetaData.o InputMismatchException.o RuleContextWithAltNum.o Vocabulary.o ListTokenSource.o ANTLRErrorListener.o CommonTokenFactory.o TokenStreamRewriter.o CharStream.o ANTLRFileStream.o Lexer.o ProxyErrorListener.o ANTLRErrorStrategy.o RuleContext.o BufferedTokenStream.o LexerInterpreter.o Recognizer.o IntStream.o InterpreterRuleContext.o ParserInterpreter.o TokenSource.o BailErrorStrategy.o CommonTokenStream.o DefaultErrorStrategy.o CommonToken.o NoViableAltException.o ParserRuleContext.o RecognitionException.o Parser.o ANTLRInputStream.o Token.o LexerNoViableAltException.o WritableToken.o BlockStartState.o StarBlockStartState.o BlockEndState.o Transition.o EmptyPredictionContext.o ParseInfo.o ATNConfig.o LexerTypeAction.o AtomTransition.o AmbiguityInfo.o ATNSimulator.o LexerIndexedCustomAction.o RuleTransition.o TokensStartState.o PredicateTransition.o SingletonPredictionContext.o LexerMoreAction.o ATNDeserializationOptions.o LoopEndState.o LexerActionExecutor.o LexerATNSimulator.o SetTransition.o LexerModeAction.o NotSetTransition.o ProfilingATNSimulator.o LexerATNConfig.o DecisionInfo.o ATNState.o ATNSerializer.o ArrayPredictionContext.o PredictionMode.o LookaheadEventInfo.o ATN.o SemanticContext.o RuleStopState.o OrderedATNConfigSet.o RangeTransition.o ATNDeserializer.o PlusBlockStartState.o WildcardTransition.o ActionTransition.o ParserATNSimulator.o DecisionState.o RuleStartState.o ErrorInfo.o StarLoopbackState.o BasicState.o AbstractPredicateTransition.o PredictionContext.o LexerAction.o LL1Analyzer.o EpsilonTransition.o LexerCustomAction.o PrecedencePredicateTransition.o PlusLoopbackState.o LexerPopModeAction.o PredicateEvalInfo.o LexerSkipAction.o ContextSensitivityInfo.o ATNConfigSet.o LexerChannelAction.o BasicBlockStartState.o DecisionEventInfo.o LexerPushModeAction.o StarLoopEntryState.o DFAState.o DFASerializer.o DFA.o LexerDFASerializer.o InterpreterDataReader.o IntervalSet.o Predicate.o MurmurHash.o Interval.o CPPUtils.o Any.o StringUtils.o Arrays.o guid.o TerminalNodeImpl.o ErrorNode.o Trees.o ParseTreeListener.o ParseTree.o ParseTreeVisitor.o ErrorNodeImpl.o ParseTreeWalker.o IterativeParseTreeWalker.o TerminalNode.o RuleTagToken.o ParseTreeMatch.o TokenTagToken.o Chunk.o ParseTreePatternMatcher.o TextChunk.o TagChunk.o ParseTreePattern.o XPathLexerErrorListener.o XPathRuleElement.o XPathElement.o XPathWildcardAnywhereElement.o XPathRuleAnywhereElement.o XPathWildcardElement.o XPathLexer.o XPath.o XPathTokenAnywhereElement.o XPathTokenElement.o
HDRS = $(srcdir)/MySqlParserVisitor.h $(srcdir)/MySqlParser.h $(srcdir)/MySqlParserBaseListener.h $(srcdir)/MySqlLexer.h $(srcdir)/MySqlParserListener.h $(srcdir)/MySqlParserBaseVisitor.h
LOCAL_HDRS = 
TARGET = python_parser
TARGET_NAME = python_parser
TARGET_ENTRY = Init_$(TARGET_NAME)
DLLIB = $(TARGET).bundle
EXTSTATIC = 
STATIC_LIB = 

TIMESTAMP_DIR = .

BINDIR        = $(bindir)

RUBYCOMMONDIR = $(sitedir)$(target_prefix)

RUBYLIBDIR    = $(sitelibdir)$(target_prefix)

RUBYARCHDIR   = $(sitearchdir)$(target_prefix)

HDRDIR        = $(rubyhdrdir)/ruby$(target_prefix)

ARCHHDRDIR    = $(rubyhdrdir)/$(arch)/ruby$(target_prefix)

TARGET_SO_DIR =
TARGET_SO     = $(TARGET_SO_DIR)$(DLLIB)
CLEANLIBS     = $(TARGET_SO) 
CLEANOBJS     = *.o  *.bak


all:    $(DLLIB)
static: $(STATIC_LIB)
.PHONY: all install static install-so install-rb
.PHONY: clean clean-so clean-static clean-rb

clean-static::
clean-rb-default::
clean-rb::
clean-so::
clean: clean-so clean-static clean-rb-default clean-rb
		-$(Q)$(RM) $(CLEANLIBS) $(CLEANOBJS) $(CLEANFILES) .*.time

distclean-rb-default::
distclean-rb::
distclean-so::
distclean-static::
distclean: clean distclean-so distclean-static distclean-rb-default distclean-rb
		-$(Q)$(RM) Makefile $(RUBY_EXTCONF_H) conftest.* mkmf.log
		-$(Q)$(RM) core ruby$(EXEEXT) *~ $(DISTCLEANFILES)
		-$(Q)$(RMDIRS) $(DISTCLEANDIRS) 2> /dev/null || true

realclean: distclean
install: install-so install-rb

install-so: $(DLLIB) $(TIMESTAMP_DIR)/.sitearchdir.time
	$(INSTALL_PROG) $(DLLIB) $(RUBYARCHDIR)
clean-static::
	-$(Q)$(RM) $(STATIC_LIB)
install-rb: pre-install-rb do-install-rb install-rb-default
install-rb-default: pre-install-rb-default do-install-rb-default
pre-install-rb: Makefile
pre-install-rb-default: Makefile
do-install-rb:
do-install-rb-default:
pre-install-rb-default:
	@$(NULLCMD)
$(TIMESTAMP_DIR)/.sitearchdir.time:
	$(Q) $(MAKEDIRS) $(@D) $(RUBYARCHDIR)
	$(Q) $(TOUCH) $@

site-install: site-install-so site-install-rb
site-install-so: install-so
site-install-rb: install-rb

.SUFFIXES: .c .m .cc .mm .cxx .cpp .o .S

.cc.o:
	$(ECHO) compiling $(<)
	$(Q) $(CXX) $(INCFLAGS) $(CPPFLAGS) $(CXXFLAGS) $(COUTFLAG)$@ -c $(CSRCFLAG)$<

.cc.S:
	$(ECHO) translating $(<)
	$(Q) $(CXX) $(INCFLAGS) $(CPPFLAGS) $(CXXFLAGS) $(COUTFLAG)$@ -S $(CSRCFLAG)$<

.mm.o:
	$(ECHO) compiling $(<)
	$(Q) $(CXX) $(INCFLAGS) $(CPPFLAGS) $(CXXFLAGS) $(COUTFLAG)$@ -c $(CSRCFLAG)$<

.mm.S:
	$(ECHO) translating $(<)
	$(Q) $(CXX) $(INCFLAGS) $(CPPFLAGS) $(CXXFLAGS) $(COUTFLAG)$@ -S $(CSRCFLAG)$<

.cxx.o:
	$(ECHO) compiling $(<)
	$(Q) $(CXX) $(INCFLAGS) $(CPPFLAGS) $(CXXFLAGS) $(COUTFLAG)$@ -c $(CSRCFLAG)$<

.cxx.S:
	$(ECHO) translating $(<)
	$(Q) $(CXX) $(INCFLAGS) $(CPPFLAGS) $(CXXFLAGS) $(COUTFLAG)$@ -S $(CSRCFLAG)$<

.cpp.o:
	$(ECHO) compiling $(<)
	$(Q) $(CXX) $(INCFLAGS) $(CPPFLAGS) $(CXXFLAGS) $(COUTFLAG)$@ -c $(CSRCFLAG)$<

.cpp.S:
	$(ECHO) translating $(<)
	$(Q) $(CXX) $(INCFLAGS) $(CPPFLAGS) $(CXXFLAGS) $(COUTFLAG)$@ -S $(CSRCFLAG)$<

.c.o:
	$(ECHO) compiling $(<)
	$(Q) $(CC) $(INCFLAGS) $(CPPFLAGS) $(CFLAGS) $(COUTFLAG)$@ -c $(CSRCFLAG)$<

.c.S:
	$(ECHO) translating $(<)
	$(Q) $(CC) $(INCFLAGS) $(CPPFLAGS) $(CFLAGS) $(COUTFLAG)$@ -S $(CSRCFLAG)$<

.m.o:
	$(ECHO) compiling $(<)
	$(Q) $(CC) $(INCFLAGS) $(CPPFLAGS) $(CFLAGS) $(COUTFLAG)$@ -c $(CSRCFLAG)$<

.m.S:
	$(ECHO) translating $(<)
	$(Q) $(CC) $(INCFLAGS) $(CPPFLAGS) $(CFLAGS) $(COUTFLAG)$@ -S $(CSRCFLAG)$<

$(TARGET_SO): $(OBJS) Makefile
	$(ECHO) linking shared-object $(DLLIB)
	-$(Q)$(RM) $(@)
	$(Q) $(LDSHAREDXX) -o $@ $(OBJS) $(LIBPATH) $(DLDFLAGS) $(LOCAL_LIBS) $(LIBS)
	$(Q) $(POSTLINK)



$(OBJS): $(HDRS) $(ruby_headers)
