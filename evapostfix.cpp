#include "stack.h"
#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

double evapostfix(char* expression[],int numtokens){
    stack<double> numbers;
    double left, right, result = 0;

    for(int i = 0; i < numtokens; i++){
        //Addition
        if(*expression[i] == '+'){
        right = numbers.top();
        numbers.pop();
        left = numbers.top();
        numbers.pop();
        numbers.push(left + right);
        }
        //Subtraction
        else if(*expression[i] == '-'){
        right = numbers.top();
        numbers.pop();
        left = numbers.top();
        numbers.pop();
        numbers.push(left - right);
        }
        //Multiplication
        else if(*expression[i] == '*'){
        right = numbers.top();
        numbers.pop();
        left = numbers.top();
        numbers.pop();
        numbers.push(left * right);
        }
        //Division
        else if(*expression[i] == '/'){
        right = numbers.top();
        numbers.pop();
        left = numbers.top();
        numbers.pop();
        numbers.push(left / right);
        }  
        //Numbers
        else{
            numbers.push(atof(expression[i])); 
        }
    }

    result = numbers.top();
    numbers.pop();
    return result;

}

#define MAXLEN 100

int main(){               
    do{ 
        char answer;
        char *tokens[MAXLEN/2]; 
        char input[MAXLEN];
        cout << "\nEnter an arithmetic expression in postfix notation\n\n"
        << "Make sure to separate each token with a space: ";
        cin.getline(input,MAXLEN);
        
        char *ptr = strtok(input," ");

        int count = 0;
        while(ptr  != NULL){
            tokens[count] = ptr;
            count++;
            ptr = strtok(NULL," ");
        }

        double result = evapostfix(tokens,count);
        cout << "\nResult: " << result << endl;
 
        cout << "\nDo you want to try another one?(y/n) ";

        cin >> answer; 
        cin.ignore();
        if (answer != 'y')
            break;
        
    }while(true);

    return 0;
}
