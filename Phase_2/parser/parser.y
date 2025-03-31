%define api.value.type variant
%{
    #include <iostream>
    #include <string>
    #include <cstring>
    #include<vector>
    using namespace std;

    int yyerror(char *yaccProvidedMessage);
    int yylex(void);

    extern int yylineno;
    extern char *yytext;
    extern FILE *yyin;

%}

%token <string *> KEYWORD
%token <string *> OPERATOR
%token <int> INTCONST
%token <double> REAL
%token <string *> STRING
%token <string *> PUNCTUATION
%token <string *> ID

%start program

%%

program: stmt
    | program stmt
;

stmt:   expr PUNCTUATION { 
        if(*$1 != ";") yyerror("Line not finished with ;"); YYERROR;
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
;

op: OPERATOR {
        string validOps[11] = {"+", "-", "/", "*", "%", ">", ">=", "<", "<=", "==", "!="};
        bool found = false;
        for (const string& op : validOps) {
            if ($1 == op) {
                found = true;
                break;
            }
        }
        if (!found) {
            yyerror("Invalid operator");
            YYERROR;
        }
    }
    | KEYWORD {
        if(*$1 != "and" || *$1 != "or") yyerror("Invalid operator"); YYERROR;
    }
;

term: PUNCTUATION expr PUNCTUATION{
        if(*$1 != "(") yyerror("Term does not begin with ("); YYERROR;
        if(*$2 != ")") yyerror("Term does not end with )"); YYERROR;
    }
    | OPERATOR expr{
        if(*$1 != "-") yyerror("Term cannot does not begin -"); YYERROR;
    }
    | KEYWORD expr{
        if(*$1 != "not") yyerror("Term does not begin with not"); YYERROR;
    }
    | OPERATOR lvalue{
        if(*$1 != "++" || *$1 != "--") yyerror("Term must begin with \"++\" or \"--\""); YYERROR;
    }
    | lvalue OPERATOR{
        if(*$1 != "++" || *$1 != "--") yyerror("Term must end with \"++\" or \"--\""); YYERROR;
    }
    | primary
;

assignexpr: lvalue op expr {if(*$1 != "=") yyerror("Operator must be \"=\" in assignment expressions"); YYERROR;}
;

primary: lvalue
    | call
    | objectdef
    | OPERATOR funcdef OPERATOR{
        if(*$1 != "(") yyerror("primary does not begin with ("); YYERROR;
        if(*$2 != ")") yyerror("primary does not end with )"); YYERROR;
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
        if(*$1 != ".") yyerror("punctuation in member must be \".\""); YYERROR;
    }
    | lvalue PUNCTUATION expr PUNCTUATION{
        if(*$1 != "[") yyerror("member can only contain ["); YYERROR;
        if(*$2 != "]") yyerror("member can only contain ]"); YYERROR;
    }
    | call PUNCTUATION ID{
        if(*$1 != ".") yyerror("punctuation in member must be \".\""); YYERROR;
    }
    | call PUNCTUATION expr PUNCTUATION{
        if(*$1 != "[") yyerror("member can only contain ["); YYERROR;
        if(*$2 != "]") yyerror("member can only contain ]"); YYERROR; 
    }
;

call: call PUNCTUATION elist PUNCTUATION{
        if(*$1 != "(") yyerror("Invalid punctuation"); YYERROR;
        if(*$2 != ")") yyerror("Invalid punctuation"); YYERROR;
    }
    | lvalue callsuffix
    | PUNCTUATION funcdef PUNCTUATION PUNCTUATION elist PUNCTUATION{
        if(*$1 != "(" || *$2 != ")") yyerror("Invalid call must be \"( function )\""); YYERROR;
        if(*$3 != "(" || *$4 != ")") yyerror("Invalid call must be \"( function ) ( expr )\""); YYERROR;
    }
;

callsuffix: normcall
    | methodcall
;

normcall: PUNCTUATION elist PUNCTUATION {
        if(*$1 != "(") yyerror("normcall must begin with ("); YYERROR;
        if(*$2 != ")") yyerror("normcall must end with )"); YYERROR; 
    }
;

methodcall: PUNCTUATION ID PUNCTUATION elist PUNCTUATION {
        if(*$1 != "..") yyerror("methodcall must begin with \"..\""); YYERROR;
        if(*$3 != "(" || *$3 != ")") yyerror("Invalid methodcall must be like \"..id(elist)\""); YYERROR;
    }
;

elist: 
    | expr
    | elist PUNCTUATION expr{
        if(*$1 != ",") yyerror("Invalid punctuation in elist"); YYERROR; 
    }
;

objectdef: PUNCTUATION PUNCTUATION{
        if(*$1 != "[") yyerror("objectdef must begin with ["); YYERROR;
        if(*$2 != "]") yyerror("objectdef must end with ]"); YYERROR;
    } 
    | PUNCTUATION elist PUNCTUATION{
        if(*$1 != "[") yyerror("objectdef must begin with ["); YYERROR;
        if(*$2 != "]") yyerror("objectdef must end with ]"); YYERROR;
    }
;

indexed: indexedelemlist
;

indexedelemlist: 
    | indexedelem
    | indexedelemlist PUNCTUATION indexedelem {if(*$1 != ",") yyerror("punctuation must be , in indexed"); YYERROR;}
;

indexedelem: PUNCTUATION expr PUNCTUATION expr PUNCTUATION {
    if(*$1 != "{" || *$3 != "}") yyerror("indexedelem does not contain { or }"); YYERROR;
    if(*$3 != ":") yyerror("indexedelem does not contain :"); YYERROR;
}
;

block: PUNCTUATION stmtlist PUNCTUATION {if(*$1 != "{" || *$2 != "}") yyerror("wrong punctuation in block"); YYERROR;}
;

stmtlist: 
    | stmt
    | stmtlist stmt
;

funcdef: KEYWORD PUNCTUATION idlist PUNCTUATION block {
        if(*$1 != "function") yyerror("Invalid keyword in funcdef"); YYERROR;
        if(*$2 != "(" || *$3 != ")") yyerror("function must have (params)"); YYERROR;
    }
    | KEYWORD ID PUNCTUATION idlist PUNCTUATION block {
        if(*$1 != "function") yyerror("Invalid keyword in funcdef"); YYERROR;
        if(*$3 != "(" || *$4 != ")") yyerror("function must have (params)"); YYERROR;
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
    | idlist PUNCTUATION ID {if(*$1 != ",") yyerror("Wrong punctuation in idlist"); YYERROR;}
;

ifstmt:  KEYWORD PUNCTUATION expr PUNCTUATION stmt{
        if(*$1 != "if") yyerror("Invalid keyword in ifstmt"); YYERROR;
        if(*$2 != "(" || *$3 != ")") yyerror("Invalid punctuation in ifstmt"); YYERROR;
    }
    | KEYWORD PUNCTUATION expr PUNCTUATION stmt KEYWORD stmt{
        if(*$1 != "if" || *$4 != "else") yyerror("Invalid keyword in ifstmt"); YYERROR;
        if(*$2 != "(" || *$3 != ")") yyerror("Invalid punctuation in ifstmt"); YYERROR; 
    }
;

whilestmt: KEYWORD PUNCTUATION expr PUNCTUATION stmt {
        if(*$1 != "while") yyerror("Invalid keyword in whilestmt"); YYERROR;
        if(*$2 != "(" || *$3 != ")") yyerror("Invalid punctuation in whilestmt"); YYERROR; 
    }
;

forstmt: KEYWORD PUNCTUATION elist PUNCTUATION expr PUNCTUATION elist PUNCTUATION stmt{]
    if(*$1 != "for") yyerror("Invalid keyword in forstmt"); YYERROR;
    if(*$2 != "(" || *$5 != ")") yyerror("forstmt does not contain ()"); YYERROR;
    if(*$3 != ";" || *$4 != ";") yyerror("forstmt must be like for(elist; expr; elist) mprokoloko"); YYERROR;
}
;

returnstmt: KEYWORD PUNCTUATION {
        if(*$1 != "return") yyerror("Den les return sto returnstmt"); YYERROR;
        if(*$2 != ";") yyerror("Den exeis balei ; meta to return"); YYERROR;
    }
    | KEYWORD expr PUNCTUATION{
        if(*$1 != "return") yyerror("Den les return sto returnstmt"); YYERROR;
        if(*$2 != ";") yyerror("Den exeis balei ; meta to return"); YYERROR;
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

