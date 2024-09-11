#include <iostream>
using namespace std; 

struct Node{
    int data; 
    Node *next; 
};

struct Node *TOP = NULL; 


void StackPush(int value, Node*& TOP){
    struct Node *new_node = new Node(); 
    new_node -> data = value; 
    if (TOP == NULL) {
        new_node -> next = NULL; 
        TOP = new_node; 
    }
    else{
        new_node -> next = TOP; 
        TOP = new_node; 
    }
}


void StackPop(Node*& TOP){
    if (TOP == NULL) {
        cout << "UNDERFLOW..."<<endl;
    }
    else {
        struct Node *ptr = TOP;
        TOP = TOP -> next;
        free(ptr);
    }
}


void StackDisplay(){
    cout << "Current Stack Using Linked List: " << endl; 
    struct Node *temp = TOP; 
    while (temp != NULL) {
        cout << temp -> data << endl; 
        temp = temp -> next; 
    }
    cout << endl; 
}


int main() {
    int choice; 
    while (choice != 0) {
        cout << "Choose From Following Stack Operations" << endl; 
        cout << "0. To Exit" << endl; 
        cout << "1. To Push Data" << endl; 
        cout << "2. To Pop One Data" << endl; 
        cout << "3. To Display Stack" << endl; 
        cout << "> "; 
        cin >> choice; 


        switch (choice) {
            case 1: 
                int val; 
                cout << "Enter Value: "; 
                cin >> val; 

                StackPush(val, TOP);
                cout<<endl; 
                break;
            case 2:
                StackPop(TOP);
                cout<<endl; 
                break; 
            case 3: 
                StackDisplay(); 
                break; 
            default: 
                cout<<endl; 
                continue; 
        }
    }
}