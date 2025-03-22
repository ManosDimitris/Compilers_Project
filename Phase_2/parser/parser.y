%{
    #include <stdio.h>

    void yyerror(char *errormeseage){
        cerr << "Error: " << errormeseage << endl;
    }
%}



%left ADD /* + */
%left MUL,DIV /* * / */ 
%right /* ++ */ 
%right /* -- */
%nonassoc EQ,DIF /* == != */