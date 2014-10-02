#include<iostream>
using namespace std;

#define MAX 1000
#define UNAVAILABLE -1

long memo[MAX]; 

long fibo (long n) {
    
    if (memo[n] != UNAVAILABLE) return memo[n];
    if (n<=2) return 1;
    else memo[n] = fibo(n-1) + fibo(n-2); 
    return memo[n];   
}

int main() {


    int i;
        
    for(i = 0; i< MAX; i++) {
        memo[i] = UNAVAILABLE;    
    }

    for(i=1; i<90; i++) {
        cout << "Fibo(" << i << ") = \t" << fibo(i);
        cout << endl;   
    }
}
