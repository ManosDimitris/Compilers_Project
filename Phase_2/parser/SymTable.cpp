#include"SymTable.hpp"



SymbolTable::SymbolTable() {
    for (int i = 0; i < CAPACITY; i++) {
        table[i] = nullptr;
    }
    
}


void SymbolTable::display() {
    for (int i = 1; i < CAPACITY; i++) {
        if (table[i] != nullptr) {  
            cout << "Index " << i << ": ";
            SymbolEntry* current = table[i]; 
            while (current != nullptr) {
                cout << "[" << current->name << ", Scope: " << current->scope << ", Line: " << current->line << "] ";
                current = current->next; 
            }
            cout << endl;
        }
    }

    if (table[0]!= nullptr) {    
        SymbolEntry* tmp = table[0]; 

        while (tmp != nullptr) {
            cout << "Index " << tmp->scope << ": ";
            cout << "[" << tmp->name << ", Scope: " << tmp->scope << ", Line: " << tmp->line << "] " << endl;
            tmp = tmp->nextSc; 
        }
    
    }
}

void SymbolTable::insert(string name, int scope, int line) {
    int index = SymTable_hash(name);
    SymbolEntry* newEntry = new SymbolEntry(name, scope, line); // Allocate a new node

    if (table[index] == nullptr) {
        table[index] = newEntry; // If bucket is empty, insert at head
    } 
    else {
        SymbolEntry* temp = table[index];
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newEntry;
    }

    ScopeList *new_scope = new ScopeList(newEntry);
    if(scopes == nullptr){
        scopes = new_scope;
    }else{
        ScopeList* tmp = scopes;
        ScopeList* prev = scopes;
        while(tmp->next != nullptr){
            if(tmp->data->scope==new_scope->data->scope){
                SymbolEntry* tmp_SymbolScope=tmp->data;
            
                while(tmp_SymbolScope->next!=nullptr){
                    tmp_SymbolScope=tmp_SymbolScope->next;
                }
                tmp_SymbolScope->next=newEntry;
                return;
            }
            else if(tmp->data->scope > new_scope->data->scope){
                if (prev == nullptr) {
                    new_scope->next = scopes;
                    scopes = new_scope;
                } else {
                    prev->next = new_scope;
                    new_scope->next = tmp;
                }
                return;
            }
            prev = tmp;
            tmp = tmp->next;
        }
        prev->next=new_scope;
    }

}


int SymbolTable::SymTable_hash(string name) {
    int hash = 0;
    for (char c : name) {
        hash = (hash * HASH_MUL + c) % CAPACITY;
    }
    return (hash == 0) ? 1 : hash;  
}
