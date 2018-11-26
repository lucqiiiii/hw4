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

//#define MAXLEN 100
int main(){

    string input;
    
    cout << "Enter a fully parenthesized infix expression: ";
    getline(cin,input); 
    
    cout << convert(input) << endl;

/*
    char input[MAXLEN];

    cout << "Enter a fully parenthesized infix expression: ";
    cin.getline(input,MAXLEN);
    
    int count = 0;
    while(input[count] != '\0'){
        count++;
    }

    int length = count;
    for(int i = 0; i < length; i++){
        if(input[i] == ' '){
            input[count].splice(i,1);
            length--;
        }
        else if(input[i] == '('){
            input[count].splice(i,1);
            length--;
        }
        else if(isdigit(input[i])){
            char num = input[i];
            int len = 1;
            int t = i+1;
            while(isdigit(input[t])){
                num += input[t];
                t++;
                len++;
            }
            input[i] = num;
            input[count].splice(i+1,len-1);
            length -= (len-1);
        }
        else{
            continue;
        }
    }
    
    char *token[length];
    for(int i = 0; i < length; i++){
        *token[i] = input[i];
        cout << token[i] << endl;
    }

   
    char *ptr = strtok(input," ");

    int count = 0;
    while(ptr != NULL){
        cout << ptr[count] << endl;
        tokens[count] = ptr;
        count++;
        
        ptr = strtok(NULL," ");
    }
   
    string result = convert(tokens,count);
    cout << result << endl;
*/
    return 0;
}
    
