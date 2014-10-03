
/* This solution will make 1.5n comparisons in the worst case */

#include<iostream>
using namespace std;

#define MAX 100

int main() {

    int arr[MAX], i, max, min;
    
    /* Make some random array to test code */
    for (i=0; i<MAX; i++) {
        arr[i] = rand() % 500;    
    }
    cout << endl << "Original array is:" << endl;

    /* Print the array */
    for (i=0; i<MAX; i++) {
        cout << "\t" << arr[i];
    }


    /* First initialize max and min to the the first element of the array */
    max = min = arr[0];

    /* In this approach we first compare two adjacent elements and then compare 
     * the greater one with max and smaller one with min
     */
    int num1, num2, num;
    for (i=0; i < MAX/2; i++) {
        
           num1 = arr[2*i];
           num2 = arr[2*i+1];
           
           // Comparing two numbers first
           if (num1 >= num2) {
               // Compare greater one with max
               if (num1 > max){
                   max = num1;
               }
               if(num2 < min){
                   min = num2;    
               }
           }
           else{
                // Compaare greater one with max
               if(num2 > max){ 
                   max = num2;    
               }
               if(num1 < min){
                   min = num1;
               }
           }
    }
   
    // Remaining element in the array 
    if (i*2 < MAX) {
        num = arr[i*2];        
        if(num > max){ 
           max = num;    
        }
        if(num < max){
           min = num;
        }
    }

    cout << endl << "Maximum: \t" << max << endl << "Minimum: \t" << min << endl;
    return 0;

}
