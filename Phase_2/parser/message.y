%{
    #include <iostream>
    #include <string>
    #include <vector>
    #include <unordered_map>

    using namespace std;
    int yylex(void);
    extern int yylineno;
    extern string string_buff;
    

    // Symbol table structure
    struct Symbol {
        string name;
        string type; // "variable", "function", "library", "argument"
        int line;
        int scope;
        bool is_local;
    };

    vector<unordered_map<string, Symbol>> symbol_table;
    int current_scope = 0;
    bool in_function = false;

    void print_symbol_table();
    void add_symbol(const string& name, const string& type, int line, bool is_arg = false);
    void enter_scope();
    void exit_scope();
    void yyerror(const char *s);
%}

%union {
    int int_val;
    double real_val;
    char* str_val;
}

%token INTCONST REAL STRING
%token IF ELSE WHILE FOR FUNCTION RETURN BREAK CONTINUE AND NOT OR LOCAL
%token TRUE FALSE NIL
%token EQUAL ASSIGN PPLUS PLUS MMINUS MINUS MULTI DIV MOD NEQUAL
%token GREATER_EQUAL LESS_EQUAL GREATER LESS
%token LEFT_CBRACKET RIGHT_CBRACKET LEFT_BRACKET RIGHT_BRACKET
%token LEFT_PARENTHES RIGHT_PARENTHES SEMICOLON COMMA DCOLON COLON DOTS DOT
%token ID

%right ASSIGNdw
%left OR
%left AND
%left EQUAL NEQUAL
%left LESS GREATER LESS_EQUAL GREATER_EQUAL
%left PLUS MINUS
%left MULTI DIV MOD
%right NOT
%left PPLUS MMINUS

%start program

%%

program: stmt_list
        ;

stmt_list: /* empty */
        | stmt_list stmt
        ;

stmt: expr SEMICOLON
        | if_stmt
        | while_stmt
        | for_stmt
        | return_stmt
        | BREAK SEMICOLON
        | CONTINUE SEMICOLON
        | block
        | func_def
        | SEMICOLON
        ;

expr: assign_expr
        | expr PLUS expr
        | expr MINUS expr
        | expr MULTI expr
        | expr DIV expr
        | expr MOD expr
        | expr GREATER expr
        | expr GREATER_EQUAL expr
        | expr LESS expr
        | expr LESS_EQUAL expr
        | expr EQUAL expr
        | expr NEQUAL expr
        | expr AND expr
        | expr OR expr
        | term
        ;

assign_expr: lvalue ASSIGN expr
        ;

term: LEFT_PARENTHES expr RIGHT_PARENTHES
        | MINUS expr %prec NOT
        | NOT expr
        | PPLUS lvalue
        | lvalue PPLUS
        | MMINUS lvalue
        | lvalue MMINUS
        | primary
        ;

primary: lvalue
        | call
        | object_def
        | LEFT_PARENTHES func_def RIGHT_PARENTHES
        | const
        ;

lvalue: ID
        | LOCAL ID
        | DCOLON ID
        | member
        ;

member: lvalue DOT ID
        | lvalue LEFT_BRACKET expr RIGHT_BRACKET
        | call DOT ID
        | call LEFT_BRACKET expr RIGHT_BRACKET
        ;

call: call LEFT_PARENTHES elist RIGHT_PARENTHES
        | lvalue call_suffix
        | LEFT_PARENTHES func_def RIGHT_PARENTHES LEFT_PARENTHES elist RIGHT_PARENTHES
        ;

call_suffix: norm_call
        | method_call
        ;

norm_call: LEFT_PARENTHES elist RIGHT_PARENTHES
        ;

method_call: DOTS ID LEFT_PARENTHES elist RIGHT_PARENTHES
        ;

elist: /* empty */
        | expr
        | elist COMMA expr
        ;

object_def: LEFT_BRACKET LEFT_BRACKET elist RIGHT_BRACKET RIGHT_BRACKET
        | LEFT_BRACKET LEFT_BRACKET indexed RIGHT_BRACKET RIGHT_BRACKET
        ;

indexed: indexed_elem
        | indexed COMMA indexed_elem
        ;

indexed_elem: LEFT_CBRACKET expr COLON expr RIGHT_CBRACKET
        ;

block: LEFT_CBRACKET stmt_list RIGHT_CBRACKET
        ;

func_def: FUNCTION ID LEFT_PARENTHES id_list RIGHT_PARENTHES block
        | FUNCTION LEFT_PARENTHES id_list RIGHT_PARENTHES block
        ;

id_list: /* empty */
        | ID
        | id_list COMMA ID
        ;

if_stmt: IF LEFT_PARENTHES expr RIGHT_PARENTHES stmt
        | IF LEFT_PARENTHES expr RIGHT_PARENTHES stmt ELSE stmt
        ;

while_stmt: WHILE LEFT_PARENTHES expr RIGHT_PARENTHES stmt
        ;

for_stmt: FOR LEFT_PARENTHES elist SEMICOLON expr SEMICOLON elist RIGHT_PARENTHES stmt
        ;

return_stmt: RETURN SEMICOLON
        | RETURN expr SEMICOLON
        ;

const: INTCONST
        | REAL
        | STRING
        | NIL
        | TRUE
        | FALSE
        ;

%%

void yyerror(const char *s) {
    cerr << "Error at line " << yylineno << ": " << s << endl;
    exit(1);
}

void add_symbol(const string& name, const string& type, int line, bool is_arg) {
    // Check if symbol already exists in current scope
    if (symbol_table[current_scope].count(name)) {
        cerr << "Error at line " << line << ": redeclaration of '" << name << "'" << endl;
        exit(1);
    }
    
    // Check if trying to shadow
    // a library function
    if (type != "library" && symbol_table[0].count(name) && symbol_table[0][name].type == "library") {
        cerr << "Error at line " << line << ": cannot shadow library function '" << name << "'" << endl;
        exit(1);
    }
    
    Symbol sym;
    sym.name = name;
    sym.type = type;
    sym.line = line;
    sym.scope = current_scope;
    sym.is_local = (current_scope > 0) && !is_arg;
    
    symbol_table[current_scope][name] = sym;
}

void enter_scope() {
    symbol_table.push_back(unordered_map<string, Symbol>());
    current_scope++;
}

void exit_scope() {
    if (current_scope > 0) {
        symbol_table.pop_back();
        current_scope--;
    }
}

void print_symbol_table() {
    cout << "\nSymbol Table:\n";
    cout << "------------\n";
    
    for (size_t scope = 0; scope < symbol_table.size(); ++scope) {
        cout << "Scope " << scope << ":\n";
        
        for (const auto& entry : symbol_table[scope]) {
            const Symbol& sym = entry.second;
            cout << "  Name: " << sym.name 
                 << ", Type: " << sym.type
                 << ", Line: " << sym.line
                 << ", Scope: " << sym.scope
                 << ", Local: " << (sym.is_local ? "yes" : "no") << endl;
        }
    }
}

int main(int argc, char* argv[]) {
    // Initialize global scope
    symbol_table.push_back(unordered_map<string, Symbol>());
    
    // Add library functions to global scope
    vector<string> library_funcs = {
        "print", "input", "objectmemberkeys", "objecttotalmembers", 
        "objectcopy", "totalarguments", "argument", "typeof", 
        "strtonum", "sqrt", "cos", "sin"
    };
    
    for (const auto& func : library_funcs) {
        Symbol sym;
        sym.name = func;
        sym.type = "library";
        sym.line = 0;
        sym.scope = 0;
        sym.is_local = false;
        symbol_table[0][func] = sym;
    }
    
    yyparse();
    print_symbol_table();
    return 0;
}