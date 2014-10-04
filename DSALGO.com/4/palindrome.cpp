// Given an integer, find the next palindrome to that integer

#include<iostream>
#include<string>
using namespace std;

string getNextPalindrome (string num);
int main() {

    string num;
    string palindrome;
    while (1) {
        cin >> num;
        palindrome = getNextPalindrome(num);
        cout << palindrome << endl;
    }
    return 0;
}

string getNextPalindrome(string num) {

    int len = num.length();

    // Find midpoint considering even and odd number of digits

    int mid = len/2 - (len+1)%2;
    bool bigswap = false;

    for (int i = 0; i <= mid; i++) {

        int right = mid + i + (len+1)%2; 
        int left = mid - i;

        if(!bigswap && num[right] != num[left]) {
            // make both = greater number
            num[right] = num[left] = num[right] >= num[left] ? num[right] : num[left];
            bigswap = true;
        }
        else {
            num[right] = num[left];
        }
    }
    return num;
}


