#include<iostream>
using namespace std;

int fibo (int n) {
    
    if (n<=2) return 1;
    else return fibo(n-1) + fibo(n-2);    
}

int main() {

    int i;
    for(i=1; i<60; i++) {
        cout << "Fibo(" << i << ") = \t" << fibo(i);
        cout << endl;   
    }
}
