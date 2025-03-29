%{
    #include <iostream>
    #include <string>

    using namespace std;

    int yyerror(char *yaccProvidedMessage);
    int yylex(void);

    extern int yylineno;
    extern char *yytext;
    extern FILE *yyin;

%}

%define api.value.type variant
%token <string *> KEYWORD
%token <string *> OPERATOR
%token <int> INTCONST
%token <double> REAL
%token <string *> STRING
%token <string *> PUNCTUATION
%token <string *> ID

%start program

%%
program: stmt*
;

stmt: expr ';'
    | ifstmt
    | whilestmt
    | forstmt
    | returnstmt
    | KEYWORD ';' {
        if(*$1 == "break") cout << "Found break statement" << endl;
        else if(*$1 == "continue") cout << "Found continue statement" << endl;
        else{
            yyerror("Invalid statement");
            YYERROR;
        }
    }
    | block
    | funcdef
    | ';'
;

expr: assignexpr
    | expr op expr
    | term
;

op: OPERATOR {
        string accepted_operators[11] = {"+", "-", "/", "*", "%", ">", ">=", "<", "<=", "==", "!="};
        if(&1 != "+" || &1 != "-" || &1 == "/" || &1 == "*" || &1 == "")
    }

%%

