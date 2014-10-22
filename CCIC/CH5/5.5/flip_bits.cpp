// Given two numbers, A & B, find how many bits should be flipped to transform from A to B

#include<iostream>
using namespace std;


int flip_bits(int a, int b) {
    
    //Lets consider only +ve numbers
    if (a < 0 || b < 0) {
        return -1;
    }

    // Xor will give us number of different bits
    int x;
    x = a^b;
    int count = 0;

    while(x > 0) {
        if((x & 1) == 1) {
            count++;    
        }    
        x >>= 1;
    }

    return count;
}


int main() {
    int a, b;
    while(true) {
        cout << "\nEnter A: ";
        cin >> a;
        cout << "Enter B: ";
        cin >> b;
        cout << "# of bits to flip: " << flip_bits(a,b) << endl;    
    }
}



