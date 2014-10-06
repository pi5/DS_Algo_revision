#include<iostream>
#include<string>
using namespace std;

void largest_palindrome(string str) {
    int start, end, len;
    int g_start = 0;
    int g_end = 0;
    int g_len = 0;
    int i; 
    int length = str.length();

    for ( i=1; i<length; i++) {
        // Run for even and odd cases
        for(int even = 0; even < 2; even++) {
            start = i;
            end = i + even; 
            len = 1 + even;

            while( start > 0 && end < length - 1 && str[start-1] == str[end+1]) {
                start--;
                end++;
                len += 2;
            }
            if ( len > g_len ) {
                g_len = len;
                g_start = start; 
                g_end = end; 
            }
        }
    }
    cout << endl;
    for(i = g_start; i<=g_end; i++) {
        cout << str[i];
    }
    cout<< endl;
}

int main() {

    string str;
    while(1) {
        cin >> str;
        largest_palindrome(str);
    }
    return 0;
}
