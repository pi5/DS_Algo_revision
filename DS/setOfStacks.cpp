#include<iostream>
#include<stack>
#include<vector>
#include<list>
using namespace std;

#define SIZE 3
#define MAXSTACKS 10
#define ERR_STACK_EMPTY -9999

class setOfStacks {
    int no_stacks;
    int curr_stack;
    int max_stack_size;
    stack<int>* stacks[MAXSTACKS];

    public:
    setOfStacks():no_stacks(0), curr_stack(-1), max_stack_size(SIZE) {
        // Initialize all the stack pointers
        for(int i=0; i<MAXSTACKS; i++){
            stacks[i] = NULL;
        }         
        //stacks[curr_stack] = new stack<int>;
    }

    void push(int value) {
         
        if(curr_stack==-1 || (stacks[curr_stack]->size() == max_stack_size && no_stacks < MAXSTACKS)) {
            stacks[++curr_stack] = new stack<int>;
            ++no_stacks;
            cout << endl << "No Stacks " << no_stacks << " curr_stack " << curr_stack;
        }        
        
        // Check if we still are in limit of number of stacks
        // TODO: Remove this limit
        if(no_stacks <= MAXSTACKS && stacks[curr_stack]->size() < max_stack_size){
            stacks[curr_stack]->push(value);
            cout << endl << "Stack:" << curr_stack << "\t" << "Size: " << stacks[curr_stack]->size();
        }
        else{
            cout << endl << "All stacks occupied" << endl;
            return;
        }
    }

    int pop() {
        int value = ERR_STACK_EMPTY;
        if(no_stacks == 0) {
            cout << endl << "Error: Stacks empty" << endl; 
            return ERR_STACK_EMPTY;
        }    
        else{
            // If stack becomes empty, remove it
            // and decrement curr_stack and no_stacks
            value = stacks[curr_stack]->top();
            stacks[curr_stack]->pop();
            if(stacks[curr_stack]->size() == 0) {
                free(stacks[curr_stack]);
                stacks[curr_stack] = NULL;
                curr_stack--;
                no_stacks--;
            }
            return value;
        }
    }
};

int main() {
    setOfStacks s;
    
    for(int i=0; i<32; i++) {
        s.push(i);    
    }
    for(int i=0; i<31; i++) {
        cout << endl << s.pop(); 
    }
    cout << endl;
}
