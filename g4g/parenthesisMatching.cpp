#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool matchingParens(string expr) {
    stack<char> S;
    int count = expr.length(); 
    
    if(count == 0) return true;
    
    int i = 0;
    while(i<count) {
        char c = expr[i];
        if(c == '('){
            S.push(c); 
        }
        else if (c == ')' && !S.empty() && S.top() == '('){
            S.pop();    
        }
        else
            return false;

        i++;
    }
    if(S.empty() == true) return true;
    return false;
}

int main (){
    string expr;
    
    while(true) {
        cout << endl << "Enter String:" << endl;
        cin >> expr;
        if(matchingParens(expr))
            cout << "\tMatching. Bravo!" << endl;
        else    
            cout << "\tNot Matching. I wish you typed correctly :/" << endl;
    } 
    
}
