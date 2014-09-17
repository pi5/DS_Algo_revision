#include<stdio.h>
#include<string.h>

#define true 1
#define false 0
#define maxchars 256

typedef int bool;
bool check_duplicate_chars(char*);

int main() {
    
    char string[100] = "thequickbrownfoxjumpsoverthelazydog";
    bool x = check_duplicate_chars(string);

    printf("\n\n%d\n\n", x);
}

bool check_duplicate_chars (char * s) {
    int flags[256];

    // initialze flags to 0
    for (int i = 0; i < maxchars; i++) {
        flags[i] = 0;  
    }
    
    /* Iterate over the array and check if flags are set already*/
    for (int i =0; i<strlen(s); i++) {
        if (flags[(int)s[i]] == 1) 
            return false;
        else
            flags[(int)s[i]] = 1;
    }
    return true;
}
