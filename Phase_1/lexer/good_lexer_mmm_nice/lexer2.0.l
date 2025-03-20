%{
    #include<iostream>
    #include<string>
    #include<list>
    #include <unordered_map>
    using namespace std;

    string string_buff;

%}

%option noyywrap
%option yylineno
%option c++


KEYWORD        (if|else|while|for|return|break|continue|and|not|or|local|true|false|nil)
OPERATOR       (=|\+|\-|\*|\/|%|==|!=|\+\+|\-\-|>|<|>=|<=)
INTCONST        (0[xX][0-9A-Fa-f]+)|([0-9]+)
REAL           [0-9]*\.[0-9]*
STRING         \"([^\"\\\n]|\\[\"nt\\])*\"
PUNCTUATION    (\{|\}|\[|\]|\(|\)|;|,|:|::|\.|\.\.)
ID             [a-zA-Z][a-zA-Z_0-9]*
COMMENT1       "//".*
COMMENT2       "/*"
WHITESPACE     (" "|"\n")


%%

{KEYWORD}   {cout << "Found KEYWORD " << yytext << endl;}
{OPERATOR}   {cout << "Found OPERATOR " << yytext << endl;}
{INTCONST}   {cout << "Found INTCONST " << yytext << endl;}
{REAL}   {cout << "Found REAL " << yytext << endl;}
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
            int index = 0;
            while((index = string_buff.find("\\", index)) != string::npos){
                char next_index = string_buff[index + 1];
                if(escape_map.count(next_index))
                {
                    string_buff.replace(index,2,escape_map[next_index]);
                }else{
                    cout<< "Invalid escape character" << next_index ;
                }
                index += escape_map[next_index].length();
            }
            cout << string_buff << endl;
           
           }
{PUNCTUATION}   {cout << "Found PUNCTUATION " << yytext << endl;}
{ID}   {cout << "Found ID " << yytext << endl;}
{COMMENT1}   {cout << "Found COMMENT1 " << yytext << endl;}
{COMMENT2}   {cout << "Found COMMENT2 " << yytext << endl;}
{WHITESPACE}   {}

.   { cout << "Not recognised expression: " << yytext << endl; }

%%

int main(){
    yyFlexLexer lexer;
    while (lexer.yylex() != 0);
    return 0;
}
