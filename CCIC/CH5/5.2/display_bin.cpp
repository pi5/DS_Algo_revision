#include<iostream>
#include<string>

using namespace std;

void display_bin(double d);
   
int main () {
 
    double d;
    while(1) {
        cin >> d;
        display_bin(d);   
    }  
    
}

void display_bin(double d) {
    
    string s = ".";
    double r;

    if(d<=0 || d>=1)
        cout << endl <<"Error" << endl;
        
    while(d > 0) {
        if(s.length()>32)
            break;

        r = 2*d;
        if(r>=1){
            s = s + "1";
            d = r-1;    
        }    
        else{
            s = s + "0";
            d = r;    
        }
    }   
    cout << endl << s << endl;  
}
