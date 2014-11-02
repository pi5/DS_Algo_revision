#include<iostream>
#include<iomanip>
using namespace std;

typedef struct node {

    int value;
    node* left; 
    node* right;    

} node;


node* getNode(int value) {
    node* temp = new node();
    temp->value = value;
    temp->right = temp->left = NULL;    
    return temp;
}

node* insert (node* root, int value) {
    
    if (root == NULL) {
        root = getNode(value);       
    }
    else {
        // check values with right and left subtree
        if(value <= root->value) {
            root->left = insert(root->left, value);    
        }
        else{
            root->right = insert(root->right, value);    
        }
    }
    return root;
}

void inorder (node* root) {

    if (root == NULL) return;

    inorder(root->left);
    cout << setw(5) << root->value;
    inorder(root->right);
}

int main() {

    node *root = NULL;
    //cout << "\nb1\n" << endl;
    root = insert(root, 5);    
    root = insert(root, 7);    
    root = insert(root, 3);    
    root = insert(root, 2);    
    root = insert(root, 4);
    root = insert(root, 8);    
    root = insert(root, 6);
    inorder(root); 
}
