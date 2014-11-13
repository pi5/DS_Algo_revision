// Given an array, print all subsets of size 3 which have 
// sum as zero
#include<iostream>
#include<map>
#include<array>
#include<deque>
using namespace std; 

#define MAX 5

class Tuple {
    public:
    int x,y;    
    
    Tuple(int i, int j):x(i), y(j) {};
};

int main() {
    map<int, deque<Tuple> > t;  
    //array<int, MAX> a = {-1, -2, -3, -4, -5, 0, 1, 2, 3, 4, 5}; 
    array<int, MAX> a = {-1, -2, 0, 1, 2}; 
    cout << a.size();
    //int sum2, i, j; 
    for(int i=0; i<a.size(); i++){
        for(int j=i+1; j<a.size(); j++) {
            int sum2 = a[i] + a[j];
            cout << endl << i << "\t" << j; 
            Tuple temp(i,j);
            t[sum2].push_back(temp);
        }
    }
    cout << endl;
    map<int, deque<Tuple> >::iterator it = t.begin();
    while(it!=t.end()) {
        cout << endl << it->first << "\t" << (it->second).size();   
        it++;
    }
    
    cout << endl; 
    for(int k=0; k<a.size(); k++) {
        int key = -1 * a[k];
        if(t.count(key)){
            deque<Tuple>::iterator q = t[key].begin(); 
            while(q!=t[key].end()) {
                Tuple temp = *q;                     
                if( k != temp.x && k != temp.y) {
                    cout << endl << a[temp.x] << ", " << a[temp.y] << ", " << a[k];   
                }
                cout << endl;
                q++;
            }
        }  
    }
    cout << endl;
}
