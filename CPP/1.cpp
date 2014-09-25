#include<iostream>
#include<string>
using namespace std;

#include<iomanip>
using std::setw;

void swap (int& a, int& b) {
    
    int temp = a;
    a = b;
    b = temp;    
}

int main() {
    
    int p = 5, q = 10;
    cout << setw(30) << "Value before swapping" << setw(5) << p << setw(10) << q << endl;
    swap(p, q);
    cout << setw(5) << "Value after swapping" << setw(5) << p << setw(10) << q << endl;

    return 0;
    
}
