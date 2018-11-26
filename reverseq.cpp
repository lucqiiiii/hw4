#include "queue.h"
#include <iostream>
#include "stack.h"

using namespace std;

void reverseq(queue* qq, int element){
    stack<int> num;
    for(int i = 0; i < element; i++){
        num.push(qq.qfront());
        qq.deq();
    }
    
    while(num != NULL){
        qq.enq(num.top());
        num.pop();
    }
    
    int size = qq.size();
    for(int j = 0; j < size - element; j++){
        int n = qq.front();
        qq.enq(n);
        qq.deq();
    }
}

int main(){
    queue q;
    do{
        int input = 0;
        cout << "Input an integer element to the queue (or -999 to stop): ";
        cin >> input;
        q.enq(input);
        if(input = -999){
            break;
        }
    }while(true);

    int k = 0;
    cout << "Type in the number of elements you want to reverse from the beginning of the queue: ";
    cin >> k;

    reverseq(&q,k);

    for(int i = 0; i < q.size(); i++){
        cout << q.front() << " " << endl;
    }

    return 0;
}  
