%{
    #include <iostream>
    #include <string>
    #include <cstring>
    #include<vector>

    #include "parser.hpp"

    using namespace std;

    int yyerror(char *yaccProvidedMessage);
    int yylex(void);

    extern int yylineno;
    extern char *yytext;
    extern FILE *yyin;

%}

%language "c++"
%define api.value.type variant

%token KEYWORD
%token OPERATOR
%token INTCONST
%token REAL
%token STRING
%token PUNCTUATION
%token ID

%type <string *> KEYWORD
%type <string *> OPERATOR
%type <int> INTCONST
%type <double> REAL
%type <string *> STRING
%type <string *> PUNCTUATION
%type <string *> ID
%type <string> op


%right "="
%left "or"
%left "and"
%nonassoc "==" "!="
%nonassoc ">" ">=" "<" "<="
%left "+" "-"
%left "*" "/" "%"
%right NOT UOP NEGATIVE
%left "." ".."
%left BRACKETS
%left PARENTHESIS

%start program

%%

program: stmt
    | program stmt
;

stmt:   expr PUNCTUATION { 
        if(*$2 != ";") yyerror("Line not finished with ;"); YYERROR;
    }
    | ifstmt
    | whilestmt
    | forstmt
    | returnstmt
    | KEYWORD PUNCTUATION {
        if(*$2 != ";") yyerror("Line not finished with ;"); YYERROR;

        if(*$1 == "break") cout << "Found break statement" << endl;
        else if(*$1 == "continue") cout << "Found continue statement" << endl;
        else{
            yyerror("Invalid statement");
            YYERROR;
        }
    }
    | block
    | funcdef	
    | PUNCTUATION {if(*$1 != ";") yyerror("INVALID PUNCTUATION"); YYERROR;}
;

expr: assignexpr
    | expr op expr
    | term
;

op: OPERATOR {
        string validOps[11] = {"+", "-", "/", "*", "%", ">", ">=", "<", "<=", "==", "!="};
        bool found = false;
        for (const string& op : validOps) {
            if (*$1 == op) {
                found = true;
                $$ = op;
                break;
            }
        }
        if (!found) {
            yyerror("Invalid operator");
            YYERROR;
        }
    }
    | KEYWORD {
        if(*$1 != "or") $$ = "or";
        else if(*$1 != "and") $$ = "and";
        else yyerror("Invalid operator"); YYERROR;
    }
;

term: PUNCTUATION expr PUNCTUATION{
        if(*$1 != "(") yyerror("Term does not begin with ("); YYERROR;
        if(*$3 != ")") yyerror("Term does not end with )"); YYERROR;
    } %prec PARENTHESIS
    | OPERATOR expr{
        if(*$1 != "-") yyerror("Term cannot does not begin -"); YYERROR;
    } %prec NEGATIVE
    | KEYWORD expr{
        if(*$1 != "not") yyerror("Term does not begin with not"); YYERROR;
    } %prec NOT
    | OPERATOR lvalue{
        if(*$1 != "++" || *$1 != "--") yyerror("Term must begin with \"++\" or \"--\""); YYERROR;
    } %prec UOP
    | lvalue OPERATOR{
        if(*$2 != "++" || *$2 != "--") yyerror("Term must end with \"++\" or \"--\""); YYERROR;
    } %prec UOP
    | primary
;

assignexpr: lvalue OPERATOR expr {if(*$2 != "=") yyerror("Operator must be \"=\" in assignment expressions"); YYERROR;}
;

primary: lvalue
    | call
    | objectdef
    | OPERATOR funcdef OPERATOR{
        if(*$1 != "(") yyerror("primary does not begin with ("); YYERROR;
        if(*$3 != ")") yyerror("primary does not end with )"); YYERROR;
    }
    | const
;

lvalue: ID
    | KEYWORD ID{
        if(*$1 != "local") yyerror("lvalue does not begin with keyword \"local\""); YYERROR;
    }
    | PUNCTUATION ID {
        if(*$1 != "::") yyerror("lvalue does not begin with punctuation \"::\""); YYERROR;
    }
    | member
;

member: lvalue PUNCTUATION ID{
        if(*$2 != ".") yyerror("punctuation in member must be \".\""); YYERROR;
    }
    | lvalue PUNCTUATION expr PUNCTUATION{
        if(*$2 != "[") yyerror("member can only contain ["); YYERROR;
        if(*$4 != "]") yyerror("member can only contain ]"); YYERROR;
    }
    | call PUNCTUATION ID{
        if(*$2 != ".") yyerror("punctuation in member must be \".\""); YYERROR;
    }
    | call PUNCTUATION expr PUNCTUATION{
        if(*$2 != "[") yyerror("member can only contain ["); YYERROR;
        if(*$4 != "]") yyerror("member can only contain ]"); YYERROR; 
    }
;

call: call PUNCTUATION elist PUNCTUATION{
        if(*$2 != "(") yyerror("Invalid punctuation"); YYERROR;
        if(*$4 != ")") yyerror("Invalid punctuation"); YYERROR;
    }
    | lvalue callsuffix
    | PUNCTUATION funcdef PUNCTUATION PUNCTUATION elist PUNCTUATION{
        if(*$1 != "(" || *$3 != ")") yyerror("Invalid call must be \"( function )\""); YYERROR;
        if(*$4 != "(" || *$6 != ")") yyerror("Invalid call must be \"( function ) ( expr )\""); YYERROR;
    }
;

callsuffix: normcall
    | methodcall
;

normcall: PUNCTUATION elist PUNCTUATION {
        if(*$1 != "(") yyerror("normcall must begin with ("); YYERROR;
        if(*$3 != ")") yyerror("normcall must end with )"); YYERROR; 
    }
;

methodcall: PUNCTUATION ID PUNCTUATION elist PUNCTUATION {
        if(*$1 != "..") yyerror("methodcall must begin with \"..\""); YYERROR;
        if(*$3 != "(" || *$5 != ")") yyerror("Invalid methodcall must be like \"..id(elist)\""); YYERROR;
    }
;

elist: 
    | expr
    | elist PUNCTUATION expr{
        if(*$2 != ",") yyerror("Invalid punctuation in elist"); YYERROR; 
    }
;

objectdef: PUNCTUATION PUNCTUATION{
        if(*$1 != "[") yyerror("objectdef must begin with ["); YYERROR;
        if(*$2 != "]") yyerror("objectdef must end with ]"); YYERROR;
    } 
    | PUNCTUATION elist PUNCTUATION{
        if(*$1 != "[") yyerror("objectdef must begin with ["); YYERROR;
        if(*$3 != "]") yyerror("objectdef must end with ]"); YYERROR;
    }
;

indexed: indexedelemlist
;

indexedelemlist: 
    | indexedelem
    | indexedelemlist PUNCTUATION indexedelem {if(*$2 != ",") yyerror("punctuation must be , in indexed"); YYERROR;}
;

indexedelem: PUNCTUATION expr PUNCTUATION expr PUNCTUATION {
    if(*$1 != "{" || *$3 != "}") yyerror("indexedelem does not contain { or }"); YYERROR;
    if(*$5 != ":") yyerror("indexedelem does not contain :"); YYERROR;
}
;

block: PUNCTUATION stmtlist PUNCTUATION {if(*$1 != "{" || *$3 != "}") yyerror("wrong punctuation in block"); YYERROR;}
;

stmtlist: 
    | stmt
    | stmtlist stmt
;

funcdef: KEYWORD PUNCTUATION idlist PUNCTUATION block {
        if(*$1 != "function") yyerror("Invalid keyword in funcdef"); YYERROR;
        if(*$2 != "(" || *$4 != ")") yyerror("function must have (params)"); YYERROR;
    }
    | KEYWORD ID PUNCTUATION idlist PUNCTUATION block {
        if(*$1 != "function") yyerror("Invalid keyword in funcdef"); YYERROR;
        if(*$3 != "(" || *$5 != ")") yyerror("function must have (params)"); YYERROR;
    } 
;

const: KEYWORD{
    if(*$1 != "true" || *$1 != "false" || *$1 != "nil") yyerror("not a valid value"); YYERROR;
    }
    | INTCONST
    | REAL
    | STRING
;

idlist: 
    | ID
    | idlist PUNCTUATION ID {if(*$2 != ",") yyerror("Wrong punctuation in idlist"); YYERROR;}
;

ifstmt:  KEYWORD PUNCTUATION expr PUNCTUATION stmt{
        if(*$1 != "if") yyerror("Invalid keyword in ifstmt"); YYERROR;
        if(*$2 != "(" || *$4 != ")") yyerror("Invalid punctuation in ifstmt"); YYERROR;
    }
    | KEYWORD PUNCTUATION expr PUNCTUATION stmt KEYWORD stmt{
        if(*$1 != "if" || *$6 != "else") yyerror("Invalid keyword in ifstmt"); YYERROR;
        if(*$2 != "(" || *$4 != ")") yyerror("Invalid punctuation in ifstmt"); YYERROR; 
    }
;

whilestmt: KEYWORD PUNCTUATION expr PUNCTUATION stmt {
        if(*$1 != "while") yyerror("Invalid keyword in whilestmt"); YYERROR;
        if(*$2 != "(" || *$4 != ")") yyerror("Invalid punctuation in whilestmt"); YYERROR; 
    }
;

forstmt: KEYWORD PUNCTUATION elist PUNCTUATION expr PUNCTUATION elist PUNCTUATION stmt{
    if(*$1 != "for") yyerror("Invalid keyword in forstmt"); YYERROR;
    if(*$2 != "(" || *$8 != ")") yyerror("forstmt does not contain ()"); YYERROR;
    if(*$4 != ";" || *$6 != ";") yyerror("forstmt must be like for(elist; expr; elist) mprokoloko"); YYERROR;
}
;

returnstmt: KEYWORD PUNCTUATION {
        if(*$1 != "return") yyerror("Den les return sto returnstmt"); YYERROR;
        if(*$2 != ";") yyerror("Den exeis balei ; meta to return"); YYERROR;
    }
    | KEYWORD expr PUNCTUATION{
        if(*$1 != "return") yyerror("Den les return sto returnstmt"); YYERROR;
        if(*$3 != ";") yyerror("Den exeis balei ; meta to return"); YYERROR;
    char *yaccProvidedMessage}
;
%%

yyerror(char *yaccProvidedMessage){
    cout << yaccProvidedMessage << " at line " << yylineno << endl;
}

int main(){
    yyparse();
    return 0;
}

