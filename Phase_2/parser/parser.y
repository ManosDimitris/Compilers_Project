%{
    #include <iostream>
    #include <string>
    #include <cstring>
    #include<vector>
    #include"SymTable.hpp"
    using namespace std;

    int yyerror(string yaccProvidedMessage);
    int yylex(void);

    extern int yylineno;
    extern char *yytext;
    extern FILE *yyin;

    SymbolTable symTable;
    int scope = 0;
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

%nonassoc THEN
%nonassoc ELSE

%start program

%%

program: stmntlist
;

stmntlist:  stmt
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
    | expr PLUS expr
    | expr MINUS expr
    | expr MULTI expr
    | expr DIV expr
    | expr MOD expr
    | expr GREATER expr
    | expr GREATER_EQUAL expr
    | expr LESS expr
    | expr LESS_EQUAL expr
    | expr EQUAL expr
    | expr NEQUAL expr
    | expr AND expr 
    | expr OR expr
    | term
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

assignexpr: lvalue ASSIGN expr{
    
}
;

primary: lvalue
    | call
    | objectdef
    | LEFT_PARENTHES funcdef RIGHT_PARENTHES
    | const
;

lvalue: ID {
            if(!(symTable.lookup(*$1))){
                if(scope == 0){         
                    symTable.insert(*$1, "global_variable", scope, yylineno);
                }else{
                    symTable.insert(*$1, "local_variable", scope, yylineno);
                }
            }else{
                if(!symTable.lookup(*$1,0) && !symTable.lookup(*$1, scope))
                    yyerror("Undefined refrence to " + *$1);
            }
        }
    | LOCAL ID {
        if(!symTable.lookup(*$2, scope)){ 
            symTable.insert(*$2, "local_variable", scope, yylineno);
        }
        else{
            yyerror("redefinition of " + *$2);
        }
    }
    | DCOLON ID { 
                if(!symTable.lookup(*$2,0)){
                    yyerror("Undefined refrence to " + *$2);
                }
        }
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

objectdef: LEFT_BRACKET elist RIGHT_BRACKET
    | LEFT_BRACKET indexed RIGHT_BRACKET
;

indexed: indexedelemlist
;

indexedelemlist: indexedelem
    | indexedelem COMMA indexedelemlist
;

indexedelem: LEFT_CBRACKET expr COLON expr RIGHT_CBRACKET
;

block: LEFT_CBRACKET{++scope;} stmntlist RIGHT_CBRACKET{scope--;}
;

funcdef: FUNCTION{
                    symTable.insert(*$1, "function", scope, yylineno);
                 } LEFT_PARENTHES{++scope;} idlist RIGHT_PARENTHES{scope--;} block
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

ifstmt: IF LEFT_PARENTHES expr RIGHT_PARENTHES stmt %prec THEN
    | ifstmt ELSE stmt
;

whilestmt: WHILE LEFT_PARENTHES expr RIGHT_PARENTHES stmt
;

forstmt: FOR LEFT_PARENTHES elist SEMICOLON expr SEMICOLON elist RIGHT_PARENTHES stmt
;

returnstmt: RETURN SEMICOLON
    | RETURN expr SEMICOLON
;

%%

int yyerror(string yaccProvidedMessage){
    cout << yaccProvidedMessage << " at line " << yylineno << endl;
    return 1;
}

int main(int argc, char* argv[]){
     if (argc > 1) {
        
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            cerr << "Error opening file: " << argv[1] << endl;
            return 1;
        }
    } else {
        yyin = stdin;
    }
    yyparse();
    symTable.display();
    return 0;
}

