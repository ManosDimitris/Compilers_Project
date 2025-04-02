%{
    #include<iostream>
    #include<string>
    #include<vector>
    #include <unordered_map>
    #include "../parser/parser.hpp"
    
    using namespace std;

    string string_buff;

    struct CommentNode{
        string comment_content = "";
        vector<CommentNode *> children;  
    };

    CommentNode *rootNode;

    void printTree(CommentNode *Node, int depth);
%}

%option noyywrap
%option yylineno

IF 	    	"if"
ELSE		"else"
WHILE 		"while"
FOR	    	"for"
FUNCTION	"function"
RETURN 		"return"
BREAK	  	"break"
CONTINUE	"continue"
AND		    "and"
NOT	    	"not"
OR	     	"or"
LOCAL	  	"local"
TRUE	   	"true"
FALSE	  	"false"
NIL		    "nil"

EQUAL	  	"=="
ASSIGN		"="
UPLUS		"++"
PLUS	   	"+"
UMINUS		"--"
MINUS	  	"-"
MULTI	  	"*"
DIV		    "/"
MOD	    	"%"
NEQUAL		"!="


GREATER_EQUAL	">="
LESS_EQUAL	    "<="
GREATER		">"
LESS		"<"
LEFT_CBRACKET	\{
RIGHT_CBRACKET	\}
LEFT_BRACKET	\[
RIGHT_BRACKET	\]
LEFT_PARENTHES	\(
RIGHT_PARENTHES	\)
SEMICOLON	\;
COMMA		\,
DCOLON		\:\:
COLON		\:
DOTS		\.\.
DOT		\.

INTCONST        (0[xX][0-9A-Fa-f]+)|([0-9]+)
REAL           [0-9]*\.[0-9]*
STRING          \"(\\.|[^"\\])*\"

ID             [a-zA-Z][a-zA-Z_0-9]*
LINE_COMMENT       "//".*
BLOCK_COMMENT       "/*"
WHITESPACE     (" "|"\n")
INVALID_STRING  \"([^\"\\\n]|\\.)*




%%
{IF}		{yylval.strVal = new string(yytext); return IF; }
{ELSE}		{yylval.strVal = new string(yytext); return ELSE;}
{WHILE}		{yylval.strVal = new string(yytext); return WHILE;}
{FOR}		{yylval.strVal = new string(yytext); return FOR;}
{FUNCTION}	{yylval.strVal = new string(yytext); return FUNCTION;}
{RETURN}		{yylval.strVal = new string(yytext); return RETURN;}
{BREAK}		{yylval.strVal = new string(yytext); return BREAK;}
{CONTINUE}		{yylval.strVal = new string(yytext); return CONTINUE;}
{AND}		{yylval.strVal = new string(yytext); return AND;}
{NOT}		{yylval.strVal = new string(yytext); return NOT;}
{OR}		{yylval.strVal = new string(yytext); return OR;}
{LOCAL}		{yylval.strVal = new string(yytext); return LOCAL;}
{TRUE}		{yylval.strVal = new string(yytext); return TRUE;}
{FALSE}		{yylval.strVal = new string(yytext); return FALSE;}
{NIL}		{yylval.strVal = new string(yytext); return NIL;}

{EQUAL}		{yylval.strVal = new string(yytext); return EQUAL;}
{ASSIGN}		{yylval.strVal = new string(yytext); return ASSIGN;}
{UPLUS}		{yylval.strVal = new string(yytext); return UPLUS;}
{PLUS}		{yylval.strVal = new string(yytext); return PLUS;}
{UMINUS}		{yylval.strVal = new string(yytext); return UMINUS;}
{MINUS}		{yylval.strVal = new string(yytext); return MINUS;}
{MULTI}		{yylval.strVal = new string(yytext); return MULTI;}
{DIV}		{yylval.strVal = new string(yytext); return DIV;}
{MOD}		{yylval.strVal = new string(yytext); return MOD;}
{NEQUAL}		{yylval.strVal = new string(yytext); return NEQUAL;}


{GREATER_EQUAL}		{yylval.strVal = new string(yytext); return GREATER_EQUAL;}
{LESS_EQUAL}		{yylval.strVal = new string(yytext); return LESS_EQUAL;}
{GREATER}		{yylval.strVal = new string(yytext); return GREATER;}
{LESS}		{yylval.strVal = new string(yytext); return LESS;}


{LEFT_CBRACKET}	{yylval.strVal = new string(yytext); return LEFT_CBRACKET;}
{RIGHT_CBRACKET}	{yylval.strVal = new string(yytext); return RIGHT_CBRACKET;}
{LEFT_BRACKET}	{yylval.strVal = new string(yytext); return LEFT_BRACKET;}
{RIGHT_BRACKET}	{yylval.strVal = new string(yytext); return RIGHT_BRACKET;}
{LEFT_PARENTHES}	{yylval.strVal = new string(yytext); return LEFT_PARENTHES;}
{RIGHT_PARENTHES}	{yylval.strVal = new string(yytext); return RIGHT_PARENTHES;}
{SEMICOLON}  {yylval.strVal = new string(yytext); return SEMICOLON;}
{COMMA}		{yylval.strVal = new string(yytext); return COMMA;}
{DCOLON}		{yylval.strVal = new string(yytext); return DCOLON;}
{COLON}		{yylval.strVal = new string(yytext); return COLON;}
{DOTS}		{yylval.strVal = new string(yytext); return DOTS;}
{DOT}		{yylval.strVal = new string(yytext); return DOT;}





\n        {yylineno++;}
{INTCONST}   {yylval.intVal = stoi(yytext); return INTCONST;}
{REAL}   {yylval.realVal = stod(yytext); return REAL;}
{INVALID_STRING} { cout << "Invalid String" << endl; exit(1); }
{STRING}   {string_buff = yytext;
              unordered_map<char, string> escape_map = {
                {'n', "\n"},
                {'t', "\t"},
                {'r', "\r"},
                {'b', "\b"},
                {'f', "\f"},
                {'v', "\v"},
                {'\\', "\\"},
                {'\'', "\'"},
                {'\"', "\""},
                {'?', "\?"}
            };

            if (string_buff.find("\n") != string::npos) {
                cout << "Error at line " << yylineno << ": string cannot contain an enter character" << endl;
                exit(1);
            }else{   
                int index = 0;
                while((index = string_buff.find("\\", index)) != string::npos){
                    char next_index = string_buff[index + 1];
                    if(escape_map.count(next_index))
                    {
                        string_buff.replace(index,2,escape_map[next_index]);
                    }else{
                        cout << "Error at line " << yylineno << ": unterminated string" << endl;
                        exit(1);
                    }
                    index += escape_map[next_index].length();
                }
                yylval.strVal = new string(yytext); 
                return STRING;
            }
        }

{ID}   {yylval.strVal = new string(yytext); return ID; }
{LINE_COMMENT}   { /* Not returning anything since parser only eats up comments */ }
{BLOCK_COMMENT}   {
                    int c;
                    int nested = 1;
                    CommentNode *curr_Node, *temp_node, *root = new CommentNode;

                    curr_Node = root;
                    curr_Node->comment_content += "/*";

                    while((c = cin.get()) != EOF){
                        curr_Node = root;
                        for(int i = 0; i < nested; i++){
                            curr_Node->comment_content += (char)c;
                            if(i < nested -1 && curr_Node->children.size() > 0) curr_Node = curr_Node->children.back();
                        }
                        if(nested != 0){
                            if(c == '/'){
                                if((c = cin.get()) == '*'){
                                    nested++;
                                    temp_node = new CommentNode;
                                    temp_node->comment_content += "/*";
                                    curr_Node->children.push_back(temp_node);
                                }
                                else cin.putback(c);
                            }
                            else if(c == '*'){
                                if((c = cin.get()) == '/'){
                                    nested--;
                                    curr_Node->comment_content += "/";
                                }
                                else cin.putback(c);
                            }
                            else if(c == '\n') ++yylineno;
                        }
                        else break;
                    }
                    if(c == EOF){
                        cout << "Error at line " << yylineno << ": Unterminated comment" << endl;
                        exit(1);
                    }
                    else{
                        rootNode = root;
                    }
            }

{WHITESPACE}   {}


.   { cout << "Not recognised expression: " << yytext << endl; }
