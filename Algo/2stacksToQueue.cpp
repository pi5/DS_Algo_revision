// Use 2 stacks to make a queue
#include<iostream>
#include<stack>
#define ERR_STACK_EMPTY -1*INT_MAX
using namespace std;

class myQueue {

    // The queues we will be using
    stack<int> s1;
    stack<int> s2;

    public:
    //Constructor
    myQueue() {}

    int dequeue() {
        // Always pop from stack 2
        int x;
        if(s2.empty()) {
            if(s1.empty()) {
                cout << "Queue is empty";
                return ERR_STACK_EMPTY;
            }
            else {
                while(!s1.empty()){
                    x = s1.top();
                    s1.pop();
                    s2.push(x);
                }
                s2.pop();
                return x;
            }
        }
        else {
            int x = s2.top();
            s2.pop();
            return x;
        }
    }

    void enqueue (int value) {
        s1.push(value);
        return;
    }
};

int main() {
    myQueue q;
    for(int i=0; i<11; i++){
        q.enqueue(i);    
    }    
    for(int i=0; i<12; i++){
        cout << endl << q.dequeue();    
    }    
    cout << endl;
}
