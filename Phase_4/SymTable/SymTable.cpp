#include"SymTable.hpp"
#include <string>
#include <fstream>

unsigned int programVarOffset = 0;
unsigned int funcVarOffset = 0;
unsigned int formalArgOffset = 0;

scopespace_t SymbolTable::currscopespace(){
    if(scopeSpaceCounter == 1)
        return programvar;
    else if(scopeSpaceCounter % 2 == 0)
        return formalarg;
    else
        return functionlocal;
}

SymbolTable::SymbolTable() {
    for (int i = 0; i < CAPACITY; i++) {
        table[i] = nullptr;
    }

    string x[12] = {"print", "input", "objectmemberkeys", "objecttotalmembers", "objectcopy", "totalarguments", "argument", "typeof", "strtonum", "sqrt", "cos", "sin"};
    for(int i = 0; i < 12; i++){
        insert(x[i], "library function", 0, 0);
    }
    
}


void SymbolTable::display() {
    ScopeList *temp = scopes;

    int curr_scope = 0;
    while(temp != nullptr){
        cout << "----Scope " << curr_scope << "----" << endl;
        
        //ALASKA TO scope->data_in_scope.size() se temp->data_in_scope.size() giati etrwgw seg fault se parapanw scopes 
        for(int i = 0; i < temp->data_in_scope.size(); i++){ 
            SymbolEntry *currEntry = temp->data_in_scope.at(i);//TSEKARE AN BRISKETAI SWSTA KAI STON TABLE KAI AN EINAI ACTIVE SYMATNIKOOOO
            cout << "[ " << "Name: "<< currEntry->name << ", Type: " << currEntry->type << ", Scope: " << currEntry->scope << ", Line: " << currEntry->line << "]" << endl;
        }
        curr_scope++;
        temp = temp -> next;
    }
}

void SymbolTable::insert(string name, string type, int scope, int line) {
    int index = SymTable_hash(name);
    SymbolEntry* newEntry = new SymbolEntry(name, type, scope, line, 1); 

    if(type != "user function" && type != "library function"){
        newEntry->scopespace = currscopespace();
        switch (newEntry->scopespace)
        {
        case programvar:
            programVarOffset++;
            break;
        case formalarg:
            formalArgOffset++;
            break;
        case functionlocal:
            funcVarOffset++;
            break;
        default:
            break;
        }
    }

    if (table[index] == nullptr) {
        table[index] = newEntry;
    } 
    else {
        SymbolEntry* temp = table[index];
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newEntry;
    }

    if(scopes == nullptr){
        ScopeList *new_scope = new ScopeList(newEntry,1);
        scopes = new_scope;
    }else{
        ScopeList *temp = scopes;
        for(int i = 0; i < scope; i++){
            if(temp->next != nullptr){
               temp = temp->next; 
            }
            else{
                temp->next = new ScopeList();
                temp = temp->next;
            }
        }
        temp->data_in_scope.push_back(newEntry);
    }

}


int SymbolTable::SymTable_hash(string name) {
    int hash = 0;
    for (char c : name) {
        hash = (hash * HASH_MUL + c) % CAPACITY;
    }
    return hash;  
}

bool SymbolTable::lookup(string name, int scope){
    int index = SymTable_hash(name);

    SymbolEntry* tmp = table[index];
    while(tmp != nullptr){
            
        if(tmp->isActive){
            if(((name == tmp->name) && (tmp->scope == scope))){
                return true; //FOUND
            }
        } 
        tmp = tmp->next;  
    }
    return false;//NOT FOUND DAHH
}

bool SymbolTable::lookup(string name){
    int index = SymTable_hash(name);

    SymbolEntry* tmp = table[index];
    while(tmp != nullptr){
            
        if(tmp->isActive){
            if(name == tmp->name){
                return true; //FOUND
            }
        } 
        tmp = tmp->next;  
    }
    return false;//NOT FOUND DAHH
}


//KANEI HIDE KRIBEI KA8E SYMBOLO STO SCOPE OTAN KLINEI ENA BLOCK
void SymbolTable::ScopeHide(int scope){
    ScopeList *tmp = scopes;

    for (int i = 0; i < scope && tmp != nullptr; i++) {
        tmp = tmp->next;
    }

    if (tmp == nullptr) return;

    for (int i = 0; i < tmp->data_in_scope.size(); i++) {
        tmp->data_in_scope[i]->isActive = 0;
    }
    tmp->isActive = 0;

}

bool SymbolTable::isFunction(string name, int scope){
    int index = SymTable_hash(name);

    SymbolEntry* tmp = table[index];
    while(tmp != nullptr){
        if(tmp->isActive){
            if((name == tmp->name) && tmp->type == "user function"){
                return true;
            }
        } 
        tmp = tmp->next;  
    }
    return false;//NOT FOUND DAHH}
}


SymbolEntry* SymbolTable::returnSymbol(string name){
    int index = SymTable_hash(name);

    SymbolEntry* tmp = table[index];
    while(tmp != nullptr){
            
        if(tmp->isActive){
            if(name == tmp->name){
                return tmp;
            }
        } 
        tmp = tmp->next;  
    }
    return nullptr;
}
