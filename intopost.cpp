#include <iostream>
#include <cstring>
#include "stack.h"

using namespace std;

string convert(string infix){
    stack<char> op;
    string postfix;

    for(int i = 0; i < infix.length(); i++){
        if(infix[i] == '('){
            continue;
        }

        else if(infix[i] == ' '){
            continue;
        }

        else if(infix[i] == '+'){
            op.push(infix[i]);
        }

        else if(infix[i] == '-'){
            op.push(infix[i]);
        }

        else if(infix[i] == '*'){
            op.push(infix[i]);
        }

        else if(infix[i] == '/'){
            op.push(infix[i]);
        }

        else if(infix[i] == ')'){
            postfix += op.top();
            postfix += ' ';
            op.pop();
        }
        
        else if(isdigit(infix[i])){
            string num;
            num += infix[i];
            int t = i+1;
            while(isdigit(infix[t])){
                num += infix[t];
                t++;
                i++;
            }
            postfix += num;
            postfix += ' ';
        }

        else{
            postfix += infix[i];
            postfix += ' ';
        }
    }

    return postfix;
}

int main(){

    string input;
    
    cout << "Enter a fully parenthesized infix expression: ";
    getline(cin,input); 
    
    cout << convert(input) << endl;

    return 0;
}
    
