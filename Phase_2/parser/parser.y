%{
    #include <stdio.h>

    void yyerror(char *errormeseage){
        cerr << "Error: " << errormeseage << endl;
    }
%}



%left '+'
%left '*' 
%left '/'
%right "++" 
%right "--"