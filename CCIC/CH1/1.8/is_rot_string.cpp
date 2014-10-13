#include<iostream>
#include<string>
using namespace std;


// Check if s1 is a rotation of s2
bool is_rot_substring(string s1, string s2) {
    
    if(s2.length() == 0) {
        return false;
    }

    string combined = s1 + s1;
    int pos = combined.find(s2, 0);
    if(pos == combined.npos) {
        return false;    
    }
    else 
        return true;
    
}

int main() {
    
    string s1;
    string s2;
    
    while(1) {
        cout << endl << "Enter string 1:";
        cin >> s1;    
        cout << endl << "Enter string 1:";
        cin >> s2;
        if(is_rot_substring(s1,s2)) cout << "YES";
        else cout << "NO";
        cout << endl;
    }   
    
}
