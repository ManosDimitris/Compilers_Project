CC = g++
LEX = flex
YACC = bison

LEX_SRC = ./lexer/lexer.l
LEX_OUT = ./lexer/lexer.yy.cpp

YACC_SRC = ./parser/parser.y
YACC_OUT = ./parser/parser.cpp
YACC_HDR = ./parser/parser.hpp

SYM_TABLE_SRC = ./parser/SymTable.cpp

EXEC = Cucumber

all: $(EXEC)

$(LEX_OUT): $(LEX_SRC)
	$(LEX) -o $@ $<

$(YACC_OUT): $(YACC_SRC)
	$(YACC) -y -d -o $@ $<

$(EXEC): $(LEX_OUT) $(YACC_OUT) $(SYM_TABLE_SRC)
	$(CC) -o $@ $(LEX_OUT) $(YACC_OUT) $(SYM_TABLE_SRC)

run: $(EXEC)
	./$(EXEC)

clean:
	rm -f $(EXEC) $(LEX_OUT) $(YACC_OUT) $(YACC_HDR)
