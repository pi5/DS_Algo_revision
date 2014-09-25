/* Reference as a return value */

#include<iostream>
#include<string>
using namespace std;

#include<iomanip>
using std::setw;


int arr[] = {10,20,30,40,50,60};

/* Returns the reference of array element on given index */
int& return_reference(int index) {
    return arr[index];    
}

int main() { 
    
    int i;
    cout << endl;
    for ( i=0; arr[i]!='\0'; i++) {
        return_reference(i) += 1;    
        cout << "\t" << arr[i];
    }
    cout << endl;
        
    return 0;
}


