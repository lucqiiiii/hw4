#include "listQ.h"
#include <iostream>
#include "stack.h"

using namespace std;

void reverseq(Queue<int>& qq, int element){
    stack<int> num;
    for(int i = 0; i < element; i++){
        num.push(qq.qfront());
        qq.dequeue();
    }
    
    while(!num.empty()){
        qq.enqueue(num.top());
        num.pop();
    }
    
    int size = qq.getSize();
    
    for(int j = 0; j < size - element; j++){
        int n = qq.qfront();
        qq.enqueue(n);
        qq.dequeue();
    }
}

void printq(Queue<int> theq){
  
    while(theq.getSize()!= 0){
        cout << theq.qfront() << " ";
        theq.dequeue();
    }
    cout << endl;
}




int main(){
    Queue<int> q;
    while(true){
        int input;
        cout << "Input an integer element to the queue (or -999 to stop): ";
        cin >> input;
        cin.ignore();
        if(input == -999){
            break;
        } 
        q.enqueue(input);
    }

    int k = 0;
    cout << "Type in the number of elements you want to reverse from the beginning\n"
    << "The order of the queue will reverse until then: ";
    cin >> k;

    reverseq(q,k);
    
    printq(q);
    cout << endl;

    return 0;
}  
