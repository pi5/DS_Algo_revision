// Use 2 queues to make a stack
#include<iostream>
#include<queue>
#define ERR_STACK_EMPTY -1*INT_MAX
using namespace std;

class myStack {

    // The queues we will be using
    queue<int> q1;
    queue<int> q2;

    public:
    //Constructor
    myStack() {}

    int pop() {
        if(q1.empty()) {
            cout << "Stack emtpy";
            return ERR_STACK_EMPTY;   
        }
        else{
            int x;
            while(q1.size() > 1){
                x = q1.front();
                q2.push(x);
                q1.pop();    
            }
            x = q1.front();
            queue<int> temp = q1; 
            q1 = q2; 
            q2 = temp;
            return x;
        }
    }

    void push (int value) {
        q1.push(value);
        return;
    }
};

int main() {
    myStack s1;
    for(int i=0; i<11; i++){
        s1.push(i);    
    }    
    for(int i=0; i<11; i++){
        cout << endl << s1.pop();    
    }    
    cout << endl;
}
