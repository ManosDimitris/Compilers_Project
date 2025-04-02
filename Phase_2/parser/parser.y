%{
    #include <iostream>
    #include <string>
    #include <cstring>
    #include<vector>

    using namespace std;

    int yyerror(char *yaccProvidedMessage);
    int yylex(void);

    extern int yylineno;
    extern char *yytext;
    extern FILE *yyin;

%}

%union{
    std::string *strVal;
    int intVal;
    double realVal;
}

%token <strVal> IF ELSE WHILE FOR FUNCTION RETURN BREAK CONTINUE AND OR LOCAL TRUE FALSE NIL
%token <strVal> EQUAL ASSIGN UPLUS PLUS UMINUS MINUS MULTI DIV MOD NEQUAL
%token <intVal> INTCONST
%token <realVal> REAL
%token <strVal> STRING
%token <strVal> GREATER_EQUAL LESS_EQUAL GREATER LESS LEFT_CBRACKET RIGHT_CBRACKET LEFT_BRACKET RIGHT_BRACKET LEFT_PARENTHES RIGHT_PARENTHES SEMICOLON COMMA DCOLON COLON DOTS DOT
%token <strVal> ID

%right ASSIGN
%left OR
%left AND
%nonassoc EQUAL NEQUAL
%nonassoc GREATER GREATER_EQUAL LESS LESS_EQUAL
%left PLUS MINUS
%left MULTI DIV MOD
%right NOT UMINUS UPLUS
%left DOT DOTS
%left LEFT_BRACKET RIGHT_BRACKET
%left LEFT_PARENTHES RIGHT_PARENTHES

%start program

%%

program: stmntlist
;

stmntlist: 
    | stmt
    | stmntlist stmt
;

stmt: expr SEMICOLON
    | ifstmt
    | whilestmt
    | forstmt
    | returnstmt
    | BREAK SEMICOLON
    | CONTINUE SEMICOLON
    | block
    | funcdef
    | SEMICOLON
;

expr: assignexpr
    | expr op expr
    | term
;

op: PLUS
    | MINUS
    | MULTI
    | DIV
    | MOD
    | GREATER
    | GREATER_EQUAL
    | LESS
    | LESS_EQUAL
    | EQUAL
    | NEQUAL
    | AND
    | OR 
;

term: LEFT_PARENTHES expr RIGHT_PARENTHES
    | MINUS expr
    | NOT expr
    | UPLUS lvalue
    | lvalue UPLUS
    | UMINUS lvalue
    | lvalue UMINUS
    | primary
;

assignexpr: lvalue ASSIGN expr
;

primary: lvalue
    | call
    | objectdef
    | LEFT_PARENTHES funcdef RIGHT_PARENTHES
    | const
;

lvalue: ID
    | LOCAL ID
    | DCOLON ID
    | member
;

member: lvalue DOT ID
    | lvalue LEFT_BRACKET expr RIGHT_BRACKET
    | call DOT ID
    | call LEFT_BRACKET expr RIGHT_BRACKET
;

call: call LEFT_PARENTHES elist RIGHT_PARENTHES
    | lvalue callsuffix
    | LEFT_PARENTHES funcdef RIGHT_PARENTHES LEFT_PARENTHES elist RIGHT_PARENTHES
;

callsuffix: normcall
    | methodcall
;

normcall: LEFT_PARENTHES elist RIGHT_PARENTHES
;

methodcall: DOTS ID LEFT_PARENTHES elist RIGHT_PARENTHES
;

elist:
    | expr
    | elist COMMA expr
;

objectdef: LEFT_BRACKET RIGHT_BRACKET
    | LEFT_BRACKET elist RIGHT_BRACKET
    | LEFT_BRACKET indexed RIGHT_BRACKET
;

indexed: indexedelemlist
;

indexedelemlist: 
    | indexedelem
    | indexedelem COMMA indexedelemlist
;

indexedelem: LEFT_CBRACKET expr COLON expr RIGHT_CBRACKET
;

block: LEFT_CBRACKET stmntlist RIGHT_CBRACKET
;

funcdef: FUNCTION LEFT_PARENTHES idlist RIGHT_PARENTHES block
    | FUNCTION ID LEFT_PARENTHES idlist RIGHT_PARENTHES block
;

const: INTCONST
    | REAL
    | STRING
    | NIL
    | TRUE
    | FALSE
;

idlist:
    | ID
    | idlist COMMA ID
;

ifstmt: IF LEFT_PARENTHES expr RIGHT_PARENTHES stmt
    | ifstmt elsestmt
;

elsestmt: ELSE stmt
;

whilestmt: WHILE LEFT_PARENTHES expr RIGHT_PARENTHES stmt
;

forstmt: FOR LEFT_PARENTHES elist SEMICOLON expr SEMICOLON elist RIGHT_PARENTHES stmt
;

returnstmt: RETURN SEMICOLON
    | RETURN expr SEMICOLON
;

%%

yyerror(char *yaccProvidedMessage){
    cout << yaccProvidedMessage << " at line " << yylineno << endl;
}

int main(){
    yyparse();
    return 0;
}

