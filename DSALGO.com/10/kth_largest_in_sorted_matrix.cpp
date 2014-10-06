#include<iostream>
using namespace std;

void printmatrix(int matrix[][4]);
int main() {

    int matrix[4][4] =
  {
  { 5, 7, 8, 9 },
  { 6, 9, 10, 13 },
  { 7, 11, 12, 15 },
  { 8, 13, 16, 17 } };


  int k; 
  cin >> k;
  int largest;
  int x,y; 
  int t, l;
  for(int i = 0; i < k; i++) {
      
      // remove largest element elements k times
      largest = matrix[3][3];
      cout << endl << i+1 << "-th largest\t" << largest << endl;
      matrix[3][3] = 0;
      x = y = 3;
      /* the void space does not reach the top*/
      
      t = matrix[x][y-1];
      l = matrix[x-1][y];
      while(t>0 || l>0) {
          //Percolate 0 till the top and remove the largest element
          
          t = l = 0;          
          if(y>0) l = matrix[x][y-1];
          if(x>0) t = matrix[x-1][y];
          if(t==0 && l==0) break;
          //cout << endl << t <<  "\t" << l << endl;  
          //cout << endl << x <<  "\t" << y << endl;  
          if(t >= l) {
              matrix[x][y] = t; 
              x = x-1;
              matrix[x][y] = 0; // percolating the void space upwards 
          }
          else {
              matrix[x][y] = l;
              y = y - 1;
              matrix[x][y] = 0; // percolating the void space leftwards
          }
          //cout << endl << x <<  "\t" << y << endl;  
          //printmatrix(matrix);
      }
  }
  
  cout << endl << k << "-th largest element is:\t" << largest << endl;

}


void printmatrix(int matrix[][4]){

    cout << endl << "--------------------------" << endl;
    for (int i = 0; i<4; i++) {  
        for (int j = 0; j<4; j++) {
            cout << "\t" <<  matrix[i][j];    
        }
        cout << endl;
    }
    cout  << endl;
}
