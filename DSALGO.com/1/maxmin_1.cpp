/* This solution will make 2n comparisons in the worst case */

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
    for(i=1; i<MAX; i++) {
        if (arr[i] < min) 
            min = arr[i];

        else if (arr[i] > max)
            max = arr[i];
    }

    cout << endl << "Maximum: \t" << max << endl << "Minimum: \t" << min << endl;
    return 0;

}
