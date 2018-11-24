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
        if(strcmp(expression[i],"+") == 0){
        right = numbers.top();
        numbers.pop();
        left = numbers.top();
        numbers.pop();
        numbers.push(left + right);
        }
        //Subtraction
        else if(strcmp(expression[i],"-") == 0){
        right = numbers.top();
        numbers.pop();
        left = numbers.top();
        numbers.pop();
        numbers.push(left - right);
        }
        //Multiplication
        else if(strcmp(expression[i],"*") == 0){
        right = numbers.top();
        numbers.pop();
        left = numbers.top();
        numbers.pop();
        numbers.push(left * right);
        }
        //Division
        else if(strcmp(expression[i],"/") == 0){
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
    result =  numbers.top();
    numbers.pop();
    return result;

}

#define MAXLEN 100

int main(){
    do{
        string answer;
        char input[MAXLEN], *tokens[MAXLEN/2];

        cout << "\nEnter an arithmetic expression in postfix notation\n"
        << "Make sure to separate each token with a space: ";
        cin.getline(input,MAXLEN);

        char *ptr = strtok(input," ");

        int count = 0;
        while(ptr != 0){
            tokens[count] = ptr;
            count++;
            ptr = strtok(0," ");
        }

        double result = evapostfix(tokens,count);
        cout << "Result: " << result << endl;
        cout << "Do you want to try another one?(y/n) ";
        cin >> answer; 
        if (answer == "n")
            break;
        
    }while(true);

    return 0;
}
