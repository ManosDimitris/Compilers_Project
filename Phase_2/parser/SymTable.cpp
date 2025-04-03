#include"SymTable.hpp"



SymbolTable::SymbolTable() {
    for (int i = 0; i < CAPACITY; i++) {
        table[i] = nullptr;
    }
    
}

/*void SymbolTable::display(){
    for (int i = 0; i < CAPACITY; i++) {
        if (!table[i].empty()) {
            cout << "Index " << i << ": ";
            for (auto &entry : table[i]) {
                cout << "[" << entry.name << ", Scope: " << entry.scope << ", Line: " << entry.line << "] "<< endl;
            }
            cout << endl;
        }
    }
}*/

void SymbolTable::display() {
    for (int i = 0; i < CAPACITY; i++) {
        if (table[i] != nullptr) {  // Check if the linked list at index i is not empty
            cout << "Index " << i << ": ";
            SymbolEntry* current = table[i]; // Start at the head of the linked list
            while (current != nullptr) {
                cout << "[" << current->name << ", Scope: " << current->scope << ", Line: " << current->line << "] ";
                current = current->next; // Move to the next node
            }
            cout << endl;
        }
    }
}

void SymbolTable::insert(string name, int scope, int line) {
    int index = hashFunction(name);
    SymbolEntry* newEntry = new SymbolEntry(name, scope, line); // Allocate a new node
    SymbolEntry* temp0 = table[0];  // Start at the head of the list
    int found=0;
    while (temp0 != nullptr) {
        if (temp0->scope == scope) {
            // Found an entry with the same scope, so chain it
            found=1;
            SymbolEntry* temp_scope = temp0;
            while (temp_scope->nextSc != nullptr) {
                temp_scope = temp_scope->nextSc;
            }
            temp_scope->nextSc = newEntry; // Append new entry in the same scope chain
            break;
        }
        temp0 = temp0->next; // Move to the next node
    }
    if(found==0){
        newEntry->next = table[0];
        table[0] = newEntry;
    }
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
}


int SymbolTable::hashFunction(string name){
    int hash = 0;
    for (char c : name) {
        hash = (hash * 31 + c) % CAPACITY-1;
    }
    return hash+1;
}
