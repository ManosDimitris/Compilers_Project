%{  
    #include <iostream>
    #include <string>
    #include <vector>


    using namespace std;

    int yyerror(string yaccProvidedMessage);
    extern int yylex(void);

    extern int yylineno;
    extern char *yytext;
    extern FILE *yyin;

%}

%union{
    std::string *strVal;
    int intVal;
    double realVal;
}

%token KEYWORD
%token OPERATOR
%token INTCONST
%token REAL
%token STRING
%token PUNCTUATION
%token ID

%type <strVal> KEYWORD
%type <strVal> OPERATOR
%type <intVal> INTCONST
%type <realVal> REAL
%type <strVal> STRING
%type <strVal> PUNCTUATION
%type <strVal> ID
%type <strVal> op

%left "or"
%left "and"
%nonassoc ">" ">=" "<" "<="
%left "+" "-"
%left "*" "/" "%"

%start program

%%

program: stmt
    | program stmt
;

stmt: expr PUNCTUATION { 
        if(*$2 != ";") yyerror("Line not finished with ;"); YYERROR;
    }   
    | KEYWORD PUNCTUATION {
        if(*$2 != ";") yyerror("Line not finished with ;"); YYERROR;

        if(*$1 == "break") cout << "Found break statement" << endl;
        else if(*$1 == "continue") cout << "Found continue statement" << endl;
        else{
            yyerror("Invalid statement");
            YYERROR;
        }
    }	
    | PUNCTUATION {if(*$1 != ";") yyerror("INVALID PUNCTUATION"); YYERROR;}
;

expr: expr op term
    | term
;

op: OPERATOR {
        string validOps[11] = {"+", "-", "/", "*", "%", ">", ">=", "<", "<=", "==", "!="};
        bool found = false;
        for (const string& op : validOps) {
            if (*$1 == op) {
                found = true;
                $$ = new string(op);
                break;
            }
        }
        if (!found) {
            yyerror("Invalid operator");
            YYERROR;
        }
    }
    | KEYWORD {
        if(*$1 != "or") $$ = new string("or");
        else if(*$1 != "and") $$ = new string("and");
        else yyerror("Invalid operator"); YYERROR;
    }
;

term: ID
    | INTCONST
    | REAL
    | STRING

%%

int yyerror(string yaccProvidedMessage){
    cout << yaccProvidedMessage << " at line " << yylineno << endl;
    return 1;
}

int main(){
    yyparse();
    return 0;
}

