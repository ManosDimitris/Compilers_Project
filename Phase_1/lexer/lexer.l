%{
    #include<iostream>
    #include<string>
    #include<list>

    using namespace std;

    #define __DEF__
    #define NESTED_COMMENT_MAX 100
    #define YYLMAX 4096
    #define NUM_OF_TOKENS 1000

    list<string> comment_buffer;
    list<string> string_buffer;
    int curr_comment = 0;

    typedef struct alpha_token {
        string token_type;   
        string value;  
        int line_number;
    } alpha_token_t;

    int alpha_yylex (void* yylval);

    typedef enum{
        KEYWORD,
        OPERATOR,
        INTCONST, 
        REAL, 
        STRING, 
        PUNCTUATION, 
        ID, 
        COMMENT1, 
        COMMENT2,
        NOT_VALID
    }Expression;

    int token_count;

%}

%option noyywrap
%option yylineno
%option c++

KEYWORD        (if|else|while|for|return|break|continue|and|not|or|local|true|false|nil)
OPERATOR       (=|\+|\-|\*|\/|%|==|!=|\+\+|\-\-|>|<|>=|<=)
INTCONST        (0[xX][0-9A-Fa-f]+)|([0-9]+)
REAL           [0-9]*\.[0-9]*
STRING         \"([^\"\\]|\\[\"nt\\])*\"
PUNCTUATION    (\{|\}|\[|\]|\(|\)|;|,|:|::|\.|\.\.)
ID             [a-zA-Z][a-zA-Z_0-9]*
COMMENT1       "//".*
COMMENT2       "/*"
WHITESPACE     " " 


%%
{WHITESPACE}   {}
{KEYWORD}    { return KEYWORD; }
{OPERATOR}    { return OPERATOR; }
{INTCONST}   { return INTCONST; }
{REAL}      { return REAL; }
{STRING}    {
            /*
            //printf("String before escape sequences: %s\n", yytext);
            int j = 0;
            
            for (int i = 1; yytext[i] != '\"'; i++) {  
                if (yytext[i] == '\\') { //skipare / kai pigene sto token 
                    i++;  
                    switch (yytext[i]) {
                        case 'n': String_buffer[j++] = '\n'; break;
                        case 't': String_buffer[j++] = '\t'; break;
                        case '\"': String_buffer[j++] = '\"'; break;
                        case '\\': String_buffer[j++] = '\\'; break;
                        default:
                            
                            //fprintf(stdout, "WARNING: Unknown token: \\%c\n", yytext[i]);
                            break;
                    }
                } else {
                    //else allo token kane store se string 
                    String_buffer[j++] = yytext[i];  
                }
            }
            //bale null terminator gia valid string
            String_buffer[j] = '\0';*/
            return STRING; 
            //fprintf(stdout, "String after: %s\n",String_buffer);
}
{PUNCTUATION}   { return PUNCTUATION; }
{ID}        { return ID; }
{COMMENT1}  { return COMMENT1; }
{COMMENT2}  { 
            /*int c;
            int nested = 1;
            int total_comments = 1;
            buff[NESTED_COMMENT_MAX][YYLMAX];
            int indexes[NESTED_COMMENT_MAX];

            memset(buff, 0, sizeof(buff));
            memset(indexes, 0, sizeof(indexes));

            buff[0][0] = '/';
            buff[0][1] = '*';
            indexes[0] = 2;

            while((c = input()) != EOF) {
                for(int i = 0; i < nested; i++){
                        buff[i][indexes[i]] = c;
                        indexes[i]++;
                }
                if(c == '/') {
                    
                    if((c = input()) == '*') {
                        nested++;
                        total_comments++;
                        for(int i = 0; i < nested; i++){
                            if(indexes[i] == 0){
                                buff[i][0] = '/';
                                indexes[i]++;
                            }
                            buff[i][indexes[i]] = c;
                            indexes[i]++;
                        }
                    } else {
                        unput(c);
                    }
                }
                else if(c == '*') {
                    
                    if((c = input()) == '/') { 
                        for(int i = 0; i < nested; i++){
                                buff[i][indexes[i]++] = '/';
                        }
                        nested--;
                        if(nested == 0) {
                            for(int i = 1; i < total_comments; i++){
                                fprintf(yyout, "Nested Comment: \"%s\"\n", buff[i]);
                            }
                            return COMMENT2; 
                        }
                    } else {
                        unput(c);
                    }
                } 
            }*/
            return COMMENT2;
}

.           { fprintf(stderr, "Not recognised expression: %s\n", yytext); }

%%

int alpha_yylex(void *yylval){
    alpha_token_t *token = (alpha_token_t *) yylval;
    
    int token_type = yylex();
    if(token_type == 0) return 0;

    token->line_number = yylineno;

    switch(token_type){
        case(KEYWORD):
            token_count++;
            strcpy(token->token_type, "KEYWORD");
            token->value = strdup(yytext);
            break;
        case(OPERATOR):
            token_count++;
            strcpy(token->token_type, "OPERATOR");
            token->value = strdup(yytext);
            break;
        case(INTCONST):
            token_count++;
            strcpy(token->token_type, "INTCONST");
            token->value = strdup(yytext);
            break;
        case(REAL):
            token_count++;
            strcpy(token->token_type, "REAL");
            token->value = strdup(yytext);
            break;
        case(STRING):
            token_count++;
            strcpy(token->token_type, "STRING");
            token->value = strdup(String_buffer);
            break;
        case(PUNCTUATION):
            token_count++;
            strcpy(token->token_type, "PUNCTUATION");
            token->value = strdup(yytext);
            break;
        case(ID):
            token_count++;
            strcpy(token->token_type, "ID");
            token->value = strdup(yytext);
            break;
        case(COMMENT1):
            token_count++;
            strcpy(token->token_type, "COMMENT1");
            token->value = strdup(yytext);
            break;
        case(COMMENT2):
            token_count++;
            strcpy(token->token_type, "COMMENT2");
            token->value = strdup(buff[curr_comment]);
            break;
        case(NOT_VALID):
            token->value = NULL;
            break;
    }
}

int main(int argc, char ** argv){
    alpha_token_t *token[NUM_OF_TOKENS];
    char categ[12];

    for(int i = 0; i < NUM_OF_TOKENS; i++){
        token[i] = malloc(sizeof(alpha_token_t));
    }

    if(argc > 1){

        if((yyin = fopen(argv[1], "r")) == NULL){
            fprintf(stderr, "CANNOT READ FILE\n");
            return 1;
        }
        
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
    for(int i = 0; alpha_yylex(token[i]) != 0; i++){
        fprintf(yyout, "Line No: %d \t #%d: Value: \"%s\" \t Category: %s\n", token[i]->line_number, token_count, token[i]->value, token[i]->token_type);
    }
    return 0;
}
