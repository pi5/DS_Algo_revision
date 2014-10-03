// Find the next larger number using the same digits in the original number

#include<iostream>
#include<string>
using namespace std;


string get_larger_number(string);

int main() {
    string a; 
    while(1){
        cin >> a;
        a = get_larger_number(a);
        cout << endl << a << endl;    
    }    
    return 0;
}

string get_larger_number(string num) {
    
    int len = num.length();
    bool swapped = false;

    // Start comparing form right to left and swap when you find a smaller number on right
    for (int i = len-1; i >= 0 && swapped == false; i--)
        for (int j = i-1; j >= 0; j--) {
            if(num[i] > num[j]) {
                char temp = num[i];
                num[i] = num[j];
                num[j] = temp;
                swapped = true;
                break;   
            }        
        }
    return num; 
}
