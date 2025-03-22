%{
    #include <stdio.h>

    void yyerror(char *errormeseage){
        cerr << "Error: " << errormeseage << endl;
    }
%}



%left ADD, SUB /* + - */
%left MUL,DIV /* * / */ 
%right /* ++ */ 
%right /* -- */