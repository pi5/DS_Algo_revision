/* Checking out cin, cout, cerr, clog */
/* When running the program, try out ./a.out 1> /dev/null and ./a.out 2> /dev/null
 */

#include<iostream>
using namespace std;

int main() {
    
    int x;
    cin >> x;
        
    cout << endl << "Test cout:\t"<< x << endl;    
    cerr << endl << "Test cerr:\t"<< x << endl;    
    clog << endl << "Test clog:\t"<< x << endl;   
    
    return 0; 
}
