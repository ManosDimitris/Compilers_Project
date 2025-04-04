#include"SymTable.hpp"
#include <string>


SymbolTable::SymbolTable() {
    for (int i = 0; i < CAPACITY; i++) {
        table[i] = nullptr;
    }
    
}


void SymbolTable::display() {
    ScopeList *temp = scopes;

    int curr_scope = 0;
    while(temp != nullptr){
        cout << "----Scope " << curr_scope << "----" << endl;
        for(int i = 0; i < scopes->data_in_scope.size(); i++){
            SymbolEntry *currEntry = temp->data_in_scope.at(i);
            cout << "[ " << "Name: "<< currEntry->name << ", Type: " << currEntry->type << ", Scope: " << currEntry->scope << ", Line: " << currEntry->line << "]" << endl;
        }
        curr_scope++;
        temp = temp -> next;
    }
}

void SymbolTable::insert(string name, string type, int scope, int line) {
    int index = SymTable_hash(name);
    SymbolEntry* newEntry = new SymbolEntry(name, type, scope, line); // Allocate a new node

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

    if(scopes == nullptr){
        ScopeList *new_scope = new ScopeList(newEntry);
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
