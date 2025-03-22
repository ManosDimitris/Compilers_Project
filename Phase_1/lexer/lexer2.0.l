%{
    #include<iostream>
    #include<string>
    #include<vector>
    #include <unordered_map>
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
                        }
                        else break;
                    }
                    if(c == EOF) cout << "Comment not terminated before end of file" << endl;
                    else{
                        rootNode = root;
                        cout << "New comment found " << endl;
                        printTree(rootNode, 0);
                    }
            }

{WHITESPACE}   {}


.   { cout << "Not recognised expression: " << yytext << endl; }

%%

int main(){
    yyFlexLexer lexer;
    while (lexer.yylex() != 0);
    return 0;
}

 void printTree(CommentNode *Node, int depth){
    cout << "Level " << depth << ": " << Node->comment_content << endl;
    //cout << "level " << depth << " has " << Node->children.size() << " nodes" << endl;
    for(CommentNode *child : Node->children){
        printTree(child, depth + 1);
    }

 }
