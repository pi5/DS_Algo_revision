#include<iostream>
#include"circularList.cpp"
#include<string>
using namespace std; 

int main() {
    int k; 
    cout << endl << "Enter number of lines to be read: ";
    cin >> k;

    CircularList<char*> a(k);

    FILE *fp = fopen("last_k_lines_of_file.cpp","r");
    char* line=NULL;
    size_t capacity=0;

    while(getline(&line, &capacity, fp) != -1) {
        a.insert(line);
        line = NULL;
        capacity=0;    
    }

    int start = a.getStart();
    cout << endl << start << endl;
    cout << endl;
    for(int i=0; i<a.getLen(); i++) {
        int index = (start+1)%a.getLen();
        cout  << a.get(start+i);    
    }
    cout << endl;
    fclose(fp);
}
