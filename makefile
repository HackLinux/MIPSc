
# stop using yacc!!
.SUFFIXES :

BISONFLAG=--debug
BISONCPP=bisonc++
FLEX=flexc++
CC=g++-4.7 -std=c++0x 
CCOPTION=-g -Wall -Wno-reorder

root=$(git rev-parse --show-toplevel)
src_dir=$(root)/src

INCLUDEDIRS = $(shell find src/ -type d -exec echo -I{} \;)

SRCS  = $(shell find src/ -name "*.cpp")
OBJS  = $(SRCS:.cpp=.o)

COMPILER=mipsc
MAIN = $(shell find src/Compiler -name "main.cc")
LEX_OBJ = src/Compiler/lex.o 
PARSER_OBJ = src/Compiler/parse.o
COMPILER_OBJ = $(LEX_OBJ) $(PARSER_OBJ)

DEFAULT : $(OBJS) $(COMPILER_OBJ)
	$(CC) $(INCLUDEDIRS) $(CCOPTION) $(MAIN) $^ -o $(COMPILER)

# ---------------------------------------------------------------------

# DEPDIR = .deps
# df = $(DEPDIR)/$(*F)

MAKEDEPEND = gcc $(INCLUDEDIRS) -M $(CPPFLAGS) -o $*.d $<

%.o : %.cpp
	@$(MAKEDEPEND); \
	cp $*.d $*.P; \
	sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
		-e '/^$$/ d' -e 's/$$/ :/' < $*.d >> $*.P; \
	rm -f $*.d
	$(CC) $(CCOPTION) -c $(INCLUDEDIRS) $(CCOPTION) -o $@ $<


-include $(SRCS:.cpp=.P)	

# ---------------------------------------------------------------------
# scanner
SCANNERDEF = $(shell find -name "scanner.lex")
SCANNERIMPL = $(shell find -name "lex.cc") 

$(SCANNERIMPL) : $(SCANNERDEF)
	cd src/Compiler && $(FLEX) $(FLEXFLAG) $(shell basename $(SCANNERDEF) )

$(LEX_OBJ) : $(SCANNERIMPL) $(shell find -name "Scanner*")
	$(CC) $(CCOPTION) $(INCLUDEDIRS) -c $(SCANNERIMPL) -o $(LEX_OBJ) 

#	cd src/Compiler && $(CC) $(CCOPTION) $(INCLUDEDIRS) -c lex.cc -o lex.o

# ----------------------------------------------------------------------------
# parser
PARSERDEF = $(shell find -name "parser.y")
PARSERIMPL = $(shell find -name "parse.cc")


$(PARSERIMPL) : $(PARSERDEF)
	cd src/Compiler && $(BISONCPP) $(BISONFLAG) $(shell basename $(PARSERDEF) )

$(PARSER_OBJ) : $(PARSERIMPL)
	$(CC) $(CCOPTION) $(INCLUDEDIRS) -c $(PARSERIMPL) -o $(PARSER_OBJ)

# ---------------------------------------------------------------------
# misc

clean :
	find -name "*.o" -exec rm {} \;
	rm tags

cleanAll :
	rm $(EXECUTABLES) ; make clean

tags : $(shell find -name "*.ih" -or -name "*.h" -or -name "*.cc" -or -name "*.cpp")
	ctags -R .