#include<stdio.h>
#include "lexer/definitions.h"

int main(int argc, char **argv){
    alpha_token_t *token;

    alpha_yylex (token);

    return 0;
}


/*int main(int argc, char ** argv){
    if(argc > 1){

        if((yyin = fopen(argv[1], "r")) == NULL){
            fprintf(stderr, "CANNOT READ FILE\n");
            return 1;
        }
        printf("got here\n");
        
        if(argc == 3){
            if((yyout = fopen(argv[2], "w")) == NULL){
                fprintf(stderr, "CANNOT WRITE TO FILE\n");
                return 1;
            }
        }
    }
    else{
        yyin = stdin;
    }
    yylex();
    return 0;
}*/