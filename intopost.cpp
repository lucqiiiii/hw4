#include <iostream>
#include <cstring>
#include "stack.h"

using namespace std;

string convert(char *infix, int length){
    stack<char> op;
    string postfix;

    for(int i = 0; i < length; i++){
        /*if(strcmp(infix[i],"(" ) == 0){
            continue;
        }
        else if(strcmp(infix[i],"+" ) == 0){
            op.push(infix[i]);
        }

        else if(strcmp(infix[i],"-" ) == 0){
            op.push(infix[i]);
        }

        else if(strcmp(infix[i],"*" ) == 0){
            op.push(infix[i]);
        }

        else if(strcmp(infix[i],"/" ) == 0){
            op.push(infix[i]);
        }

        else if(strcmp(infix[i],")" ) == 0){
            postfix.append(op.top());
            postfix += " ";
            op.pop();
        }
        
        else if(infix[i] == NULL){
            break;
        }
*/
        if(infix[i] == '('){
            continue;
        }
        else if(infix[i] == '+'){
            op.push(infix[i]);
       }
        else{
            postfix.append(infix[i]);
            postfix += " ";
        }
    }
    return postfix;
}


int main(){

    string input;
    
    cout << "Enter a fully parenthesized infix expression: ";
    cin >> input;

    int len = input.length();
    char *token[len+1];
    strcpy(token,input.c_str());

    string result;
    
    cout << convert(token,(len+1)) << endl;

    return 0;
}
    
