#include <iostream>
using namespace std; 
#define MAX 5

int queue[MAX], rear = -1, front = -1; 
void enqueue(int element) {
    if ((rear - MAX - 1 & front ==0) || front == (rear + 1) % MAX) {
        cout<<"Queue Overflow...";
        return;
    }
    else if(front == -1){
        rear++; 
        front++; 
        
        
    }else if(rear == MAX - 1 & front != 0) {
        rear = 0; 
    }else{
        rear = (rear + 1) % MAX; 
    }
    queue[rear] = element;
    cout<<"Seats Reserved:";
        for (int i= front; i <= rear; i++) {
            cout<<" "; 
            cout<<queue[i];
        }
    cout<<endl;
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
        cout<<endl<<"Seat Unreserved: " << temp << endl; 
        front++; 
        cout<<"Seats Reserved:";
        for (int i= front; i <= rear; i++) {
            cout<<" "; 
            cout<<queue[i];
        }
    }
}


void display() {
    if (front == -1 || rear == -1) {
        cout<<"No Seats Reserved... ";
    }
    else{
        cout<<"Seats Reserved: ";
            for (int i= front; i <= rear; i++) {
                cout<<" "; 
                cout<<queue[i];
            }
    }
}

int main() {
    int choice = 0, val = 1; 

    while (choice != 4) {
        cout<<endl<<"Select From The Following:\n1. Make Your Seat Reservation\n2. Delete First Reservation\n3. Display All Seat Reservation\n4. Exit"<<endl<<"> ";
        cin>>choice;

        switch (choice) {
            case 1: 
                enqueue(val); 
                val++; 
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