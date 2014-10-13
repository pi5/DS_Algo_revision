#include<iostream>
#include<iomanip>
using namespace std;

#define MAX 4 

void rot_mat (int mat[][MAX]);
void print_mat(int mat[][MAX]);

int main() {

    int i, j, count=0;
    int mat[MAX][MAX];    
    

    for(i=0; i<MAX; i++) {
        for(j=0; j<MAX; j++) {
            mat[i][j] = count++;   
        }    
    }
    print_mat(mat);
    rot_mat(mat);
    print_mat(mat);    
        
}

void print_mat(int mat[][MAX]) {
    int i, j;
    cout << endl; 
    for(i=0; i<MAX; i++) {
        for(j=0; j<MAX; j++) {
            cout << setw(5) << mat[i][j]; 
        }    
        cout << endl; 
    }
    
    cout << endl; 
}

void rot_mat (int mat[][MAX]) {
    
    int layer;

    for( layer=0; layer < MAX/2; layer++) {
        // first and last elements
        int first = layer;
        int last = MAX - 1 - layer; 
        
        for (int i = first; i < last; i++) {
            int offset = i - first;
            // Save top
            int top = mat[first][i];

            // top = left
            mat[first][i] = mat[last - offset][first];

            // left = bottom 
            mat[last - offset][first] = mat[last][last-offset];

            // bottom = right
            mat[last][last-offset] = mat[i][last];

            //right = top
            mat[i][last] = top;

        }
    }
}
