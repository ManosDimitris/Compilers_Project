%{
    #include<iostream>
    #include<string>
    #include<vector>
    #include <unordered_map>
    #include "parser.hpp"
    
    using namespace std;

    int yylineno = 0;

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
%option c++


KEYWORD        (if|else|while|for|return|break|continue|and|not|or|local|true|false|nil|function)
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
\n        {yylineno++;}
{KEYWORD}   { yylval.as<string *> = new string(yytext); return KEYWORD; }
{OPERATOR}   { yylval.as<string *> = new string(yytext); return OPERATOR; }
{INTCONST}   { yylval.as<int> = stoi(yytext); return INTCONST; }
{REAL}   { yylval.as<double> = stod(yytext); return REAL; }
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
                yylval.as<string *> = new string(yytext);
                return STRING;
            }
        }
{PUNCTUATION}   { yylval.as<string *> = new string(yytext); return PUNCTUATION; }
{ID}   { yylval.as<string *> = new string(yytext); return ID; }
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
