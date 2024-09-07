#include <iostream>
using namespace std; 
#define MAX 5

int queue[MAX], rear = -1, front = -1; 
void enqueue(int element) {
    if (MAX == rear + 1) {
        cout<<"Queue Overflow...";
        return;
    }
    else if(rear == -1 & front == -1){
        rear++; 
        front++; 
        queue[rear] = element;
        cout<<"Queue After Insertion:";
        for (int i= front; i <= rear; i++) {
            cout<<" "; 
            cout<<queue[i];
        }
    }else {
        rear++; 
        queue[rear] = element;
        cout<<"Queue After Insertion:";
        for (int i= front; i <= rear; i++) {
            cout<<" "; 
            cout<<queue[i];
        }
        cout<<endl;
    }
}


void dequeue(){
    if (front > rear || front == -1) {
        cout<<"Queue Underflow...";
        front = -1; 
        rear = -1;
        return;
    }
    else {
        int temp = queue[front];
        cout<<endl<<"Element Deleted: " << temp << endl; 
        front++; 
        cout<<"Queue After Delete:";
        for (int i= front; i <= rear; i++) {
            cout<<" "; 
            cout<<queue[i];
        }
    }
}


void display() {
    if (front == -1 || rear == -1) {
        cout<<"Queue Is Empty... ";
    }
    else{
        cout<<"Queue: ";
            for (int i= front; i <= rear; i++) {
                cout<<" "; 
                cout<<queue[i];
            }
    }
}

int main() {
    int choice = 0, val; 

    while (choice != 4) {
        cout<<endl<<"Select From The Following:\n1. Enqueue Operation\n2. Dequeue Operation\n3. Display\n4. Exit"<<endl<<"> ";
        cin>>choice;

        switch (choice) {
            case 1: 
                cout<<endl<<"Enter Element: ";
                cin>>val; 
                enqueue(val); 
                break;
            case 2: 
                dequeue(); 
                break;
            case 3:
                display();
                break;
            default:
                break;
        }
    }
}