#include<iostream>
#include<stack>
using namespace std;

class Node {
    int data;
    Node *next;
    
    public:
    Node(int value):data(value), next(NULL) {};
    //~Node(){ }   
    
    Node* getNext() {
        return next;    
    }
   
    void setNext(Node* n) {
        next = n;
    } 
    int getData() {
        return data;    
    }
};


class LinkedList {

    
    public:
    Node* head;
    Node* tail;
    LinkedList():head(NULL), tail(NULL) {}
    void insert(int data) {
        if (head == NULL) {
            head = tail = new Node(data);
        }
        else{
            if(head == tail) {
                tail = new Node(data);
                head->setNext(tail);
            }
            else {
                tail->setNext(new Node(data)); 
                tail = tail->getNext();
            }
        }
    }
   
    bool hasLoop() {
        if(head == NULL) {
            return false;    
        } 

        Node* fast = head;
        Node* slow = head;

        while(slow && fast && fast->getNext()) {
            slow = slow->getNext();
            fast = fast->getNext()->getNext();
            if (slow == fast) {
                // A loop has been found
                // Find intersecting node
                // and return true
                slow = head;
                while(slow!=fast){
                    slow = slow->getNext();
                    fast = fast->getNext();    
                }
                cout << endl << "Intersecting node value: " << slow->getData() << endl; 
                return true;    
            }    
        }
        
        // Find intersecting node
        
        return false;
    }

    

    void printList() {

        if(this->hasLoop()) {
            cout << endl << "Error: List contains loop. Go fix your list." << endl;    
            return;
        } 

        cout << endl;
        Node* h = head;
        Node* t = tail;
        
        while (h != NULL) {
            cout << h->getData() << "----";
            h = h->getNext(); 
        }   
        cout << endl;
    }
    
    bool checkIfPalindrome() {
        
        // If list has a loop, fail safely
        if(this->hasLoop()) {
            cout << endl << "Error: List contains loop. Go fix your list." << endl;    
            return false;
        } 

        // We need a fast and slow runner
        // When slow is in center, fast will have reached end
        // Also need to handle even odd cases

        stack<int> s;
        Node* fast = head;
        Node* slow = head;

        while(fast && fast->getNext()) {
            int data = slow->getData();
            s.push(data);
            slow = slow->getNext();
            fast = fast->getNext()->getNext();    
        }
        
        // If the list contains odd number of elements,
        // skip the middle element
        if(fast!=NULL) {
            slow=slow->getNext();    
        }

        while(slow!=NULL) {
            int stacktop = s.top();
            s.pop();
            if(stacktop!=slow->getData()) {
                return false;    
            }
            slow = slow->getNext();
        }

        return true;   
    }
        
};



int main() {
    
    LinkedList a;
    a.insert(5);
    a.insert(5);
    a.insert(10);
    a.insert(15);
    a.insert(10);
    a.insert(5);
    //a.insert(30);
    //a.insert(35);
    //a.insert(40);
    //a.insert(45);
    a.printList();    
    //a.tail->setNext(a.head->getNext()->getNext());
    //a.printList();    
    cout << "IsPalindrome?: " << a.checkIfPalindrome();
    cout << endl;
}
