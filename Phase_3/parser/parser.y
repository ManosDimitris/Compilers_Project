%{
    #include <iostream>
    #include <string>
    #include <cstring>
    #include <fstream>
    #include <vector>
    #include "../SymTable/SymTable.hpp"
    #include "../quad/quad.hpp"
    using namespace std;

    int yyerror(string yaccProvidedMessage);
    int yylex(void);

    extern int yylineno;
    extern char *yytext;
    extern FILE *yyin;

    SymbolTable symTable;
    int scope = 0;
    bool found_Func = false, isCall = false;
    int curr_func = 1;
    bool returnSTMT = false;
    ostream *outStream;

    bool hasLibFuncName(string name);

    /*THE VEVTOR OF THE QUADS*/
    vector<quad *> quads;
%}

%union{
    std::string *strVal;
    int intVal;
    double realVal;
    struct expr* exprVal;
}

%type <exprVal> expr assignexpr term lvalue const primary call objectdef funcdef member callsuffix normcall methodcall elist

%token <strVal> IF ELSE WHILE FOR FUNCTION RETURN BREAK CONTINUE AND OR LOCAL TRUE FALSE NIL
%token <strVal> EQUAL ASSIGN UPLUS PLUS UMINUS MINUS MULTI DIV MOD NEQUAL
%token <intVal> INTCONST
%token <realVal> REAL
%token <strVal> STRING
%token <strVal> GREATER_EQUAL LESS_EQUAL GREATER LESS LEFT_CBRACKET RIGHT_CBRACKET LEFT_BRACKET RIGHT_BRACKET LEFT_PARENTHES RIGHT_PARENTHES SEMICOLON COMMA DCOLON COLON DOTS DOT
%token <strVal> ID

%right ASSIGN
%left OR
%left AND
%nonassoc EQUAL NEQUAL
%nonassoc GREATER GREATER_EQUAL LESS LESS_EQUAL
%left PLUS MINUS
%left MULTI DIV MOD
%right NOT UMINUS UPLUS
%left DOT DOTS
%left LEFT_BRACKET RIGHT_BRACKET
%left LEFT_PARENTHES RIGHT_PARENTHES

%nonassoc THEN
%nonassoc ELSE

%start program

%%

program: 
    |stmntlist
;

stmntlist:  stmt
    | stmntlist stmt
;

stmt: expr SEMICOLON
    | ifstmt{ressettemp();}
    | whilestmt{ressettemp();}
    | forstmt
    | returnstmt
    | BREAK SEMICOLON
    | CONTINUE SEMICOLON
    | block{ressettemp();}
    | funcdef{ressettemp();}
    | SEMICOLON
;

expr: assignexpr
    | expr PLUS expr{
        $$ = NewExpr(arithexpr_e);
        expr* newTmp = newtemp();
        $$->sym = newTmp->sym;
        emit(add, $1, $3, newTmp, 0, yylineno);
    }
    | expr MINUS expr{
        $$ = NewExpr(arithexpr_e);
        expr* newTmp = newtemp();
        $$->sym = newTmp->sym;
        emit(sub, $1, $3, newTmp, 0, yylineno);
    }
    | expr MULTI expr{
        $$ = NewExpr(arithexpr_e);
        expr* newTmp = newtemp();
        $$->sym = newTmp->sym;
        emit(mul, $1, $3, newTmp, 0, yylineno);
    }
    | expr DIV expr{
        $$ = NewExpr(arithexpr_e);
        expr* newTmp = newtemp();
        $$->sym = newTmp->sym;
        emit(div_i, $1, $3, newTmp, 0, yylineno);
    }
    | expr MOD expr{
        $$ = NewExpr(arithexpr_e);
        expr* newTmp = newtemp();
        $$->sym = newTmp->sym;
        emit(mod, $1, $3, newTmp, 0, yylineno);
    }
    | expr GREATER expr{
        $$ = NewExpr(boolexpr_e);
        expr* bool_expr1 = NewExpr(constbool_e), *bool_expr2 = NewExpr(constbool_e);
        expr* new_Tmp = newtemp();

        bool_expr1->boolConst = false;

        emit(if_greater, $1, $3, nullptr, curr_quad + 3, yylineno);
        emit(assign, bool_expr1, nullptr, new_Tmp, 0, yylineno);
        emit(jump, nullptr, nullptr, nullptr, curr_quad + 2, yylineno);
        bool_expr2->boolConst = true;
        emit(assign, bool_expr2, nullptr, new_Tmp, 0, yylineno);

        $$->sym = new_Tmp->sym;
    }
    | expr GREATER_EQUAL expr{
        $$ = NewExpr(boolexpr_e);
        expr* bool_expr1 = NewExpr(constbool_e), *bool_expr2 = NewExpr(constbool_e);
        expr* new_Tmp = newtemp();

        bool_expr1->boolConst = false;

        emit(if_greatereq, $1, $3, nullptr, curr_quad + 3, yylineno);
        emit(assign, bool_expr1, nullptr, new_Tmp, 0, yylineno);
        emit(jump, nullptr, nullptr, nullptr, curr_quad + 2, yylineno);
        bool_expr2->boolConst = true;
        emit(assign, bool_expr2, nullptr, new_Tmp, 0, yylineno);

        $$->sym = new_Tmp->sym;
    }
    | expr LESS expr{
        $$ = NewExpr(boolexpr_e);
        expr* bool_expr1 = NewExpr(constbool_e), *bool_expr2 = NewExpr(constbool_e);
        expr* new_Tmp = newtemp();

        bool_expr1->boolConst = false;

        emit(if_less, $1, $3, nullptr, curr_quad + 3, yylineno);
        emit(assign, bool_expr1, nullptr, new_Tmp, 0, yylineno);
        emit(jump, nullptr, nullptr, nullptr, curr_quad + 2, yylineno);
        bool_expr2->boolConst = true;
        emit(assign, bool_expr2, nullptr, new_Tmp, 0, yylineno);

        $$->sym = new_Tmp->sym;
    }
    | expr LESS_EQUAL expr{
        $$ = NewExpr(boolexpr_e);
        expr* bool_expr1 = NewExpr(constbool_e), *bool_expr2 = NewExpr(constbool_e);
        expr* new_Tmp = newtemp();

        bool_expr1->boolConst = false;

        emit(if_lesseq, $1, $3, nullptr, curr_quad + 3, yylineno);
        emit(assign, bool_expr1, nullptr, new_Tmp, 0, yylineno);
        emit(jump, nullptr, nullptr, nullptr, curr_quad + 2, yylineno);
        bool_expr2->boolConst = true;
        emit(assign, bool_expr2, nullptr, new_Tmp, 0, yylineno);

        $$->sym = new_Tmp->sym;
    }
    | expr EQUAL expr{
        $$ = NewExpr(boolexpr_e);
        expr* bool_expr1 = NewExpr(constbool_e), *bool_expr2 = NewExpr(constbool_e);
        expr* new_Tmp = newtemp();

        bool_expr1->boolConst = false;

        emit(if_eq, $1, $3, nullptr, curr_quad + 3, yylineno);
        emit(assign, bool_expr1, nullptr, new_Tmp, 0, yylineno);
        emit(jump, nullptr, nullptr, nullptr, curr_quad + 2, yylineno);
        bool_expr2->boolConst = true;
        emit(assign, bool_expr2, nullptr, new_Tmp, 0, yylineno);

        $$->sym = new_Tmp->sym;
    }
    | expr NEQUAL expr{
        $$ = NewExpr(boolexpr_e);
        expr* bool_expr1 = NewExpr(constbool_e), *bool_expr2 = NewExpr(constbool_e);
        expr* new_Tmp = newtemp();

        bool_expr1->boolConst = false;

        emit(if_noteq, $1, $3, nullptr, curr_quad + 3, yylineno);
        emit(assign, bool_expr1, nullptr, new_Tmp, 0, yylineno);
        emit(jump, nullptr, nullptr, nullptr, curr_quad + 2, yylineno);
        bool_expr2->boolConst = true;
        emit(assign, bool_expr2, nullptr, new_Tmp, 0, yylineno);

        $$->sym = new_Tmp->sym;
    }
    | expr AND expr{
        $$ = NewExpr(boolexpr_e);
        expr* new_Tmp = newtemp();
        emit(and_i, $1, $3, new_Tmp, 0, yylineno);

        $$->sym = new_Tmp->sym;
    }
    | expr OR expr{
        $$ = NewExpr(boolexpr_e);
        expr* new_Tmp = newtemp();
        emit(or_i, $1, $3, new_Tmp, 0, yylineno);

        $$->sym = new_Tmp->sym;
    }
    | term {$$ = $1;}
;

term: LEFT_PARENTHES expr RIGHT_PARENTHES {$$ = $2;}
    | MINUS expr {
        $$ = NewExpr(var_e);
        expr* new_Tmp = newtemp();

        emit(uminus, $2, nullptr, new_Tmp, 0, yylineno);

        $$->sym = new_Tmp->sym;
    }
    | NOT expr {
        $$ = NewExpr(var_e);
        expr* new_Tmp = newtemp();

        emit(not_i, $2, nullptr, new_Tmp, 0, yylineno);

        $$->sym = new_Tmp->sym;
    }
    | UPLUS lvalue {
        $$ = NewExpr(var_e);
        expr* new_Tmp = newtemp();
        expr* one = NewExpr(constnum_e);
        one->numConst = 1;
        emit(add, $2, one, new_Tmp, 0, yylineno);
        emit(assign, new_Tmp, nullptr, $2, 0, yylineno);

        $$->sym = $2->sym;
    }
    | lvalue UPLUS {
        $$ = NewExpr(var_e);
        expr* new_Tmp = newtemp();
        expr* one = NewExpr(constnum_e);
        one->numConst = 1;
        emit(assign, new_Tmp, nullptr, $1, 0, yylineno);
        $$->sym = $1->sym;
        emit(add, $1, one, new_Tmp, 0, yylineno);
    }
    | UMINUS lvalue {
        $$ = NewExpr(var_e);
        expr* new_Tmp = newtemp();
        expr* one = NewExpr(constnum_e);
        one->numConst = -1;
        emit(add, $2, one, new_Tmp, 0, yylineno);
        emit(assign, new_Tmp, nullptr, $2, 0, yylineno);

        $$->sym = $2->sym;
    }
    | lvalue UMINUS {
        $$ = NewExpr(var_e);
        expr* new_Tmp = newtemp();
        expr* one = NewExpr(constnum_e);
        one->numConst = -1;
        emit(assign, new_Tmp, nullptr, $1, 0, yylineno);
        $$->sym = $1->sym;
        emit(add, $1, one, new_Tmp, 0, yylineno);
    }
    | primary {$$ = $1;}
;

assignexpr: lvalue ASSIGN expr{
    
    $$ = NewExpr(var_e);
    if($1->type == tableitem_e){
        emit(tablesetelem, $3, $1->index, $1, 0, yylineno);
    }else{
        emit(assign, $3, nullptr, $1, 0, yylineno);
    }
    $$ = $1;
}
;

primary: lvalue {$$ = emit_iftableitem($1);}
    | call {$$ = $1;}
    | objectdef {$$ = $1;}
    | LEFT_PARENTHES funcdef RIGHT_PARENTHES {$$ = $2;}
    | const {$$ = $1;}
;

lvalue: ID {
            if(!(symTable.lookup(*$1))){
                if(scope == 0){         
                    symTable.insert(*$1, "global_variable", scope, yylineno);
                }else{
                    symTable.insert(*$1, "local_variable", scope, yylineno);
                }
            }else{
                
                if(!symTable.lookup(*$1,0) &&!symTable.lookup(*$1, scope) && found_Func) yyerror("Undefined refrence to " + *$1);
                else if(hasLibFuncName(*$1)) yyerror("Variable " + *$1 + " cannot have the same name as a library function");
                else if(symTable.isFunction(*$1,scope) && !returnSTMT){
                        yyerror(*$1 + " Defined as function");
                }
            }
            
            SymbolEntry* entry = symTable.returnSymbol(*$1);
            if(!entry){
                yyerror("Undefined Variable: " + *$1);
                $$ = nullptr;
            } else {
                $$ = NewExpr(var_e);  
                $$->sym = entry;
            }
        }
    | LOCAL ID {
        if(scope != 0){
            if(!symTable.lookup(*$2, scope) && !(hasLibFuncName(*$2))){ 
                symTable.insert(*$2, "local_variable", scope, yylineno);
            }
            else{
                if(hasLibFuncName(*$2)) yyerror("Variable " + *$2 + " cannot have the same name as a library function");
                else yyerror("redefinition of " + *$2);
            }
        }
        else yyerror("Cannot declare local va riable with scope 0");
    }
    | DCOLON ID { 
                if(!symTable.lookup(*$2,0)){
                    yyerror("Undefined refrence to " + *$2);
                }
        }
    | member{ $$ = $1;}
;

member: lvalue DOT ID{
        $$ = member_item ($1,*$3);
}
    | lvalue LEFT_BRACKET expr RIGHT_BRACKET{
        $1 = emit_iftableitem($1);
        $$ = NewExpr(tableitem_e);
        $$->sym = $1->sym;
        $$->index = $3;
    }
    | call DOT ID
    | call LEFT_BRACKET expr RIGHT_BRACKET
;

call: call LEFT_PARENTHES elist RIGHT_PARENTHES
    | member LEFT_PARENTHES elist RIGHT_PARENTHES 
    | ID callsuffix{ $$ = $2;}
    | LEFT_PARENTHES funcdef RIGHT_PARENTHES LEFT_PARENTHES elist RIGHT_PARENTHES 
;
callsuffix: normcall { $$ = $1;}
    | methodcall{ $$ = $1; }
;

normcall: LEFT_PARENTHES elist RIGHT_PARENTHES{ $$ = $2;}
;

methodcall: DOTS ID LEFT_PARENTHES elist RIGHT_PARENTHES
;

elist :
    | expr {$$ = $1;}
    | elist COMMA expr
;

objectdef: LEFT_BRACKET elist RIGHT_BRACKET
    | LEFT_BRACKET indexed RIGHT_BRACKET
;

indexed: indexedelemlist
;

indexedelemlist: indexedelem
    | indexedelem COMMA indexedelemlist
;

indexedelem: LEFT_CBRACKET expr COLON expr RIGHT_CBRACKET
;

block: LEFT_CBRACKET{++scope;} stmntlist RIGHT_CBRACKET{
        symTable.ScopeHide(scope);
        scope--;
    }
    | LEFT_CBRACKET RIGHT_CBRACKET
;

funcdef: FUNCTION{  
        string name = "$" + to_string(curr_func);
        symTable.insert(name, "user function", scope, yylineno);
        curr_func++;
    } LEFT_PARENTHES{++scope;} idlist RIGHT_PARENTHES{scope--;} {found_Func = true;} block { found_Func = false; }
    
    | FUNCTION ID {
        bool isInSmtb = true;

        isInSmtb = symTable.lookup(*$2, scope);

        if(!isInSmtb && !hasLibFuncName(*$2)) symTable.insert(*$2, "user function", scope, yylineno);

        if(hasLibFuncName(*$2)) yyerror("user function " + *$2 + " cannot have the same id as a library function");
        else if (isInSmtb) yyerror("redefinition of " + *$2);
    }LEFT_PARENTHES{++scope;} idlist RIGHT_PARENTHES {scope--;} {found_Func = true;} block { found_Func = false; }
;

const: INTCONST {
        $$ = NewExpr(constnum_e);
        $$->numConst = $1;
    }
    | REAL{
        $$ = NewExpr(constnum_e);
        $$->numConst = $1;
    }
    | STRING{
        $$ = NewExpr(conststring_e);
        $$->strConst = *$1;
    }
    | NIL{
        $$ = NewExpr(nil_e);
    }
    | TRUE {
        $$ = NewExpr(constbool_e);
        $$->boolConst = true;
    }
    | FALSE{
        $$ = NewExpr(constbool_e);
        $$->boolConst = false;
    }
;

idlist:
    | ID {
        if(!symTable.lookup(*$1, scope) && !hasLibFuncName(*$1)){ 
            symTable.insert(*$1, "formal argument", scope, yylineno);
        }
        else{
            if(hasLibFuncName(*$1)) yyerror("Argument " + *$1 + " cannot have the same id as a library function");
            else yyerror("redefinition of " + *$1);
        }
    }
    | idlist COMMA ID {
        if(!symTable.lookup(*$3, scope) && !hasLibFuncName(*$3)){ 
            symTable.insert(*$3, "formal argument", scope, yylineno);
        }
        else{
            if(hasLibFuncName(*$3)) yyerror("Argument " + *$3 + " cannot have the same id as a library function");
            else yyerror("redefinition of " + *$3);
        }
    }
;

ifstmt: IF LEFT_PARENTHES expr RIGHT_PARENTHES stmt %prec THEN
    | ifstmt ELSE stmt
;

whilestmt: WHILE LEFT_PARENTHES expr RIGHT_PARENTHES stmt
;

forstmt: FOR LEFT_PARENTHES elist SEMICOLON expr SEMICOLON elist RIGHT_PARENTHES stmt
;

returnstmt: RETURN SEMICOLON 
    | RETURN{
        returnSTMT = 1;
    } expr{
        returnSTMT = 0;
    } SEMICOLON 
;

%%

bool hasLibFuncName(string name){
    string funcs[12] = {"print", "input", "objectmemberkeys", "objecttotalmembers", "objectcopy", "totalarguments", "argument", "typeof", "strtonum", "sqrt", "cos", "sin"};
    for(int i = 0; i < 12; i++){
        if(funcs[i] == name) return true;
    }
    return false;
}

int yyerror(string yaccProvidedMessage){
    cout << yaccProvidedMessage << " at line " << yylineno << endl;
    return 1;
}

int main(int argc, char* argv[]){
     if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file> [output_file]" << endl;
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        cerr << "Error opening input file: " << argv[1] << endl;
        return 1;
    }

    streambuf* backup = cout.rdbuf();
    ofstream file;
    if (argc >= 3) {
        file.open(argv[2]);
        if (!file.is_open()) {
            cerr << "Error opening output file: " << argv[2] << endl;
            return 1;
        }
        cout.rdbuf(file.rdbuf());
    }

    yyparse();
    symTable.display();
    printQuads();

    cout.rdbuf(backup); 
    if (file.is_open()) file.close();
    fclose(yyin);

    return 0;
}

