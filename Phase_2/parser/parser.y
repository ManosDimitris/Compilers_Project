%require "3.0"
%language "C++"
%define api.value.type variant
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

    FILE *yyout = stdout;

%}





%token <string> KEYWORD
%token <string> OPERATOR
%token <int> INTCONST
%token <double> REAL
%token <string> STRING
%token <string> PUNCTUATION
%token <string> ID

%start program

%left '+' '-'
%left '*' '/' '%'
%nonassoc UMINUS
%%
program: statements
        ;

statements:    stmt statements  
        |   /* empty */      // Empty program
        ;

stmt:   expr ';' { fprintf(yyout, "stmt ==> expr;\n"); }
    | ifstmt {fprintf(yyout,"stmt ==> ifstmt \n");}
    | whilestmt {fprintf(yyout,"stmt ==> whilestmt  \n");}
    | forstmt {fprintf(yyout,"stmt ==> forstmt \n");}
    | returnstmt {fprintf(yyout,"stmt ==> returnstmt \n");}
    | KEYWORD ';' {
        if($1 == "break") cout << "Found break statement" << endl;
        else if($1 == "continue") cout << "Found continue statement" << endl;
        else{
            yyerror("Invalid statement");
            YYERROR;
        }
    }
    | block {fprintf(yyout,"stmt ==> block \n");}
    | funcdef {fprintf(yyout,"stmt ==> funcdef \n");}	
    | ';'{fprintf(yyout,"stmt ==> ; \n");}
;

expr: assignexpr {fprintf(yyout,"expr ==> assignexpr \n");}
    | expr op expr
    | term
;

op: OPERATOR {
        string validOps[] = {"+", "-", "/", "*", "%", ">", ">=", "<", "<=", "==", "!="};
        bool found = false;
        for (const string& op : validOps) {
            if ($1 == op) {
                found = true;
                break;
            }
        }
        if (!found) {
            yyerror("Invalid operator");
            YYERROR;
        }
    }
;

term:;
block:;
funcdef:;
assignexpr:;


ifstmt:;
whilestmt:;
forstmt:;
returnstmt:;
%%

