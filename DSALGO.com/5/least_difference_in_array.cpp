/* Least difference between elements of an arry. First sort then find consecutive differences*/

#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
#define MAX 1000

int arr[] = {6,2,62,2,4,6};

int find_least_difference() {
    
    int len = sizeof(arr)/sizeof(int);
    cout << endl << len << endl;
    sort(arr, arr+len);

    int least_diff = 9999999;
    for(int i = 1; i<len; i++) {
        int diff = abs(arr[i-1] - arr[i]);
        if(diff < least_diff) {
            least_diff = diff; 
        }         
    }
    return least_diff;
}


int main() {
     
     int difference = find_least_difference();
     cout << endl << "Least difference is:\t" << difference << endl;   
     return 0;
}
