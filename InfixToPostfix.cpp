#include <cctype>
#import <iostream>
#import <string>
using namespace std;

#define MAX 100

char stack[MAX]= {}, top = -1, val, temp;
string postfix;
void push(char val) {
    if(top == MAX-1){
        cout<<"Overflow Stack.˜..\n"; 
    }else{
        top++;
        stack[top] = val;
    }
}


char pop(){
    if(top == -1){
        cout<<"Stack Underflow...";
    }else{
        temp = stack[top];
        top--;

        return temp;
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


void evaluate(string exp) {
    exp += ')'; 
    int length = exp.length();

    push('(');
    for (char ch : exp) {
        if (ch == '(') {
            push(ch);
        }
        else if(isOperator(ch) == 1) {
            if (stack[top] == '*' || stack[top] == '/') {
                char x = pop(); 
                postfix += x;

                push(ch); 
            }else {
                push(ch); 
            }
        }
        else if (isdigit(ch) || isalpha(ch)) {
            postfix += ch;
        }
        else if (ch == ')'){ 
            char ele = '\0'; 
            while (ele != '(') {
                ele = pop(); 
                if (isOperator(ele) == 1) {
                    postfix += ele; 
                }
            }
        }
    }
    
}


int main() {
    // Infix Expression: 
    string infix = "a-(b*c-d)/e";
    cout<<"Given Infix Expression: "<<infix<<endl; 
    evaluate(infix);
    cout<<endl<<"Postfix of Given Infix Expression: "<<postfix<<endl;
}
