%{
    #include <stdio.h>

    void yyerror(char *errormeseage){
        cerr << "Error: " << errormeseage << endl;
    }
%}

%token KEYWORD
%token OPERATOR
%token REAL
%token STRING
%token PUNCTUATION
%token ID

%%

