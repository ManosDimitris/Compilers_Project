#ifndef __DEF__
    #define __DEF__
    #define NESTED_COMMENT_MAX 100
    #define YYLMAX 4096
    #define NUM_OF_TOKENS 1000

    char buff[NESTED_COMMENT_MAX][YYLMAX];
    char String_buffer[1000];
    int curr_comment = 0;

    typedef struct alpha_token {
        char token_type[12];   
        char* value;  
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
#endif