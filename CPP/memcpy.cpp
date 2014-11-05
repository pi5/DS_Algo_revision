#include<iostream>
#include<string>
using namespace std;

void * myMemcpy (char* dst, char* src, int num_bytes) {
    
    int bytes = num_bytes; 
    // check for overlap
    if ((dst-src) < bytes) {
        src = src + bytes - 1;
        dst = dst + bytes - 1;
        while(bytes--){
            *dst-- = *src--;    
        }
        return (dst+1);
    }
    else {
        while(bytes--){
            *dst++ = *src++;    
        }    
        return (dst-num_bytes);
    }
}

int main() {
    
    //char a[5] = {'h','e', 'l', 'l', 'o'};
    char* a = (char*)malloc(20*sizeof(char));
    a[0] = 'h';
    a[1] = 'e';
    a[2] = 'l';
    a[3] = 'l';
    a[4] = 'o';
    a[5] = '\0';
    //char* b = (char*)malloc(6*sizeof(char));
    char *b = a+3; 
    myMemcpy(b, a, 6);
    cout << endl << b << endl;
    
}
