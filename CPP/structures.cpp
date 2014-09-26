
/* Structures */

#include<iostream>
#include<string>
using namespace std;


typedef struct
{
    string title;
    string author;
    int pages;    
} Book;


int total_pages (Book b1,Book b2) {
    return b1.pages + b2.pages;    
}


int main()
{
    Book b1;
    Book *b2;

    b1.title = "And then there were none";
    b1.author = "Agatha Christi";    
    b1.pages = 317;

    cout << endl << "Book 1" << endl;
    cout << endl << "Title:\t" << b1.title;
    cout << endl << "Author:\t" << b1.author;
    cout << endl << "Pages:\t" << b1.pages;
    cout << endl;



    b2 = (Book*) malloc(sizeof (Book));
    
    b2->title = "David and Goliath";
    b2->author = "Malcom Gladwell";
    b2->pages = 300;

    cout << endl << "Book 2" << endl; 
    cout << endl << "Title:\t" << b2->title;
    cout << endl << "Author:\t" << b2->author;
    cout << endl << "Pages:\t" << b2->pages;
    cout << endl;
    cout << endl;

    /* Notice how b1 and b2 are handled */
    cout << "Total pages:\t" << total_pages(b1, *b2);
    cout << endl;
    
    return 0;
}


