
#include<iostream>
#include<map>
using namespace std;

#define MAX 1000
#define UNAVAILABLE -1

map<int,long> memo; 

long fibo (int n) {
    
    if (memo.find(n) != memo.end()) return memo[n];
    if (n<=2) return 1;
    else memo[n] = (long)fibo(n-1) + (long)fibo(n-2); 
    return memo[n];   
}

int main() {


    int i;

    for(i=1; i<500; i++) {
        cout << "Fibo(" << i << ") = \t" << fibo(i);
        cout << endl;   
    }
}
