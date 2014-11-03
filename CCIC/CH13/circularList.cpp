#include<iostream>
using namespace std;

template <class T>
class CircularList {
    int size;
    int curr_index;
    int arr_length;
    T* arr; 

    public:
    CircularList(int sz): size(sz), curr_index(-1), arr_length(0) {
        arr = new T[size];
    }

    ~CircularList() {
        delete [] arr;
    }

    void insert (T elem) {
        curr_index = (curr_index + 1) % size;
        arr[curr_index] = elem;
        arr_length = (arr_length + 1)>size ? size:arr_length+1;
    }

    void printList() {
        if (curr_index == -1) return;

        cout << endl;
        for (int i=0; i<arr_length; i++)
            cout << "\t" << arr[i];
        cout << endl;
    }

    int getLen() {
        return arr_length;
    }
 };

int main() {
    CircularList<int> a(5);

    for(int i=0; i<20; i++) {
        a.insert(i);
        a.printList();
    }
}

