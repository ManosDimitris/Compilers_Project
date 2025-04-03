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
