#include <cctype>
#include <iostream>
#include <iterator>
#include <string>
using namespace std;
#define MAX 100

int stack[MAX]= {}, top = -1, val, temp;
void push(int val) {
    if(top == MAX-1){
        cout<<"Overflow Stack.˜..\n"; 
    }else{
        top++;
        stack[top] = val;
    }
}


int pop(){
    if(top == -1){
        cout<<"Stack Underflow...";
    }else{
        temp = stack[top];
        top--;
        return temp;
    }
    return 0; 
}

int peek(){
    if (top < 0) {
            cerr << "Stack is Empty" << std::endl;
            return 0;
        } else {
            int x = stack[top];
            return x;
    }
}


int isOperator(char symbol){
    if (
        symbol == '+' ||
        symbol == '-' ||
        symbol == '/' ||
        symbol == '*'
        ) {
            return 1;
        }
    else {
        return 0;
    }
}


int evaluate(string exp){
    // cout<<length; 

    for (char ch : exp) {
        if (isdigit(ch)) {
            push(ch - '0');
        }else {
            int operand1 = pop(); 
            int operand2 = pop();

            switch (ch) {
                case '+':
                    push(operand2 + operand1);
                    // cout<< operand2 + operand1<<endl; 
                    break;
                    
                case '-':
                    push(operand2 - operand1);
                    // cout<< operand2 - operand1<<endl; 
                    break;
                    
                case '/':
                    push(operand2 / operand1);
                    // cout<< operand2 / operand1<<endl; 
                    break;
                    
                case '*':
                    push(operand2 * operand1);
                    // cout<< operand2 / operand1<<endl; 
                    break;
                    
                default:
                    break;
            }
        }
    }

    return peek();
}

int main() {
    string postfix = "231*+9-";
    int length = sizeof(postfix)/sizeof(postfix[0]);
    // for(int i = 0; i < length; i++){
    //     expression(postfix[i]);
    // }
    int result = evaluate(postfix);

    cout<<"The Answer For Above Postfix Expression Is: "<<result<<endl;
}