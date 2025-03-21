%{
    #include<iostream>
    #include<string>
    #include<vector>
    #include <unordered_map>
    using namespace std;

    string string_buff;

    struct BlockCommentContent{
        string comment_content;
        bool isNested;
    };

    vector<BlockCommentContent *> comment_buffers;

%}

%option noyywrap
%option yylineno
%option c++


KEYWORD        (if|else|while|for|return|break|continue|and|not|or|local|true|false|nil)
OPERATOR       (=|\+|\-|\*|\/|%|==|!=|\+\+|\-\-|>|<|>=|<=)
INTCONST        (0[xX][0-9A-Fa-f]+)|([0-9]+)
REAL           [0-9]*\.[0-9]*
STRING          \"(\\.|[^"\\])*\"
PUNCTUATION    (\{|\}|\[|\]|\(|\)|;|,|:|::|\.|\.\.)
ID             [a-zA-Z][a-zA-Z_0-9]*
LINE_COMMENT       "//".*
BLOCK_COMMENT       "/*"
WHITESPACE     (" "|"\n")
INVALID_STRING  \"([^\"\\\n]|\\.)* 



%%

{KEYWORD}   {cout << "Found KEYWORD: " << yytext << endl;}
{OPERATOR}   {cout << "Found OPERATOR: " << yytext << endl;}
{INTCONST}   {cout << "Found INTCONST: " << yytext << endl;}
{REAL}   {cout << "Found REAL: " << yytext << endl;}
{INVALID_STRING} {cout << "Invalid STRING: " << yytext << endl;}
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
                cout << "Invalid STRING new line detected: " << yytext << endl;
            }else{   
                int index = 0;
                while((index = string_buff.find("\\", index)) != string::npos){
                    char next_index = string_buff[index + 1];
                    if(escape_map.count(next_index))
                    {
                        string_buff.replace(index,2,escape_map[next_index]);
                    }else{
                        cout<< "Invalid escape character " << next_index << endl;
                    }
                    index += escape_map[next_index].length();
                }
                cout <<"Found STRING: " <<string_buff << endl;
            }
        }
{PUNCTUATION}   {cout << "Found PUNCTUATION: " << yytext << endl;}
{ID}   {cout << "Found ID: " << yytext << endl;}
{LINE_COMMENT}   {cout << "Found LINE_COMMENT: " << yytext << endl;}
{BLOCK_COMMENT}   {
                    
                 }

{WHITESPACE}   {}


.   { cout << "Not recognised expression: " << yytext << endl; }

%%

int main(){
    yyFlexLexer lexer;
    while (lexer.yylex() != 0);
    return 0;
}


