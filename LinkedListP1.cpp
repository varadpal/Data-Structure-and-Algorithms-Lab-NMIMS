#include <cstddef>
#include <iostream>
using namespace std;

// initializing Structure of Node
struct Node{
    int data; 
    Node *next; 
}; 

struct Node *start = NULL; 


// Inserting First Node Function
void InsertNodeStart(int n){
    struct Node *new_node = new Node(); 
    new_node -> data=n; 
    new_node -> next=start; 
    start = new_node; 
}


// Inserting End Node Function
void InsertNodeEnd(int n){
    struct Node *new_node = new Node(); 
    new_node -> data = n; 
    new_node -> next = NULL; 
    struct Node *loc = ptr; 
}


// Traversing The Linked List
void DisplayLinkedList(){
    cout<<"The list contains the data entered:"<<endl;
    struct Node *temp = start;

    while (temp != NULL) {
        cout<<temp->data<<" -> ";
        temp = temp ->next; 
    }
    cout <<endl; 
}


// Deleting The Node
void DeleteNode(int num){
    if (start == NULL) {
        cout << "Underflow!!!"; 
    }
    else{ 
        struct Node *ptr = start; 
        struct Node *preptr = NULL; 

        while (ptr -> data != num) {
            preptr = ptr; 
            ptr = ptr ->next; 
        }

        struct Node *temp = ptr;
        preptr -> next = ptr -> next; 
        free(temp); 
    }
}


int main() {
    int choice;
    while (choice != 0) {
        cout << "0. Exit Program"<<endl;
        cout << "1. Inserting Node at End in Linked List"<<endl; 
        cout << "2. Inserting Node at Start in Linked List"<<endl; 
        cout << "3. Deleting Linked List"<<endl; 
        cout << "4. Traversing Linked List"<<endl; 
        cout << "5. Searching Linked List"<<endl;
        cout << "> "; 
        cin >> choice; 

        switch (choice) {
            case 2: 
                int val; 
                cout <<"Enter Data: "; 
                cin >> val;
                InsertNodeStart(val);
                break;
            case 3:
                int delVal; 
                cout <<"Enter Data For Delete: "; 
                cin >> delVal;
                DeleteNode(delVal); 
                break; 
            case 4: 
                DisplayLinkedList(); 
                break;
            
            
        } 
    }

}