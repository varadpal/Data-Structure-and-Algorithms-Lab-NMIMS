#include <cstdio>
#include <iostream>
using namespace std;
#define MAX 3

int stack[MAX]= {}, top = -1, val, temp;
void push(int val) {
    if(top == MAX-1){
        cout<<"Overflow Stack.˜..\n"; 
    }else{
        top++;
        cout<<endl<<"Top Position: "<<top<<endl;
        stack[top] = val;
        cout<<("Updated Stack:");
        for (int i = 0; i <= top; i++) {
            cout<<" "; 
            cout<<stack[i];
        }
    }
}


void pop(){
    if(top == -1){
        cout<<"Stack Underflow...";
    }else{
        temp = stack[top];
        cout<<endl<<"Element popped: " << temp << endl; 
        top--;
        
        cout<<("Updated Stack:");
        for (int i = 0; i <= top; i++) {
            cout<<" "; 
            cout<<stack[i];
        }
    }
}


void display(){
    cout<<("Stack Elements:");
        for (int i = 0; i <= top; i++) {
            cout<<" "; 
            cout<<stack[i];
        }
}


void popAll() {
    if(top == -1){
        cout<<"Stack Underflow...";
    }else{
        temp = stack[top];
        cout<<endl<<"Element popped: " << temp << endl; 
        top--;
        
        cout<<("Updated Stack:");
        for (int i = 0; i <= top; i++) {
            cout<<" "; 
            cout<<stack[i];
        }
        cout<<endl;

        return popAll();
    }
}

int main() { 
    int choice, val;

    do{
        cout<<("\n\nSelect From The Following Operations:\n1. Push Operation\n2. Pop Operation\n3. Display Operation\n4. Pop All Elements in Stack\n5. Exit\nEnter Choice: ");
        cin>>choice;
        switch (choice){
            case 1:
                cout<<"Enter Value To Be Pushed: ";
                cin>>val;
                push(val);
                break;
            
            case 2:
                pop();
                break;
            
            case 3:
                display(); 
                break;

            case 4:
                popAll();
                break;
            default:
                continue;
        }
    }while(choice != 5);
}