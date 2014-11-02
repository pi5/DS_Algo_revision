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

int Height(node* root) {
    if (root == NULL) return -1;
    return max(Height(root->right), Height(root->left)) + 1;    
}

node * createFromSortedArray (int arr[], int i, int j) {
    
    //cout << "\n"<< i << "\t" << j  <<"\n";
    if (j < i) return NULL;
    //if (i == j) return getNode(arr[i]);

    int mid = (j + i)/2;
    node * root = getNode(arr[mid]);
    root->left = createFromSortedArray(arr, i, mid-1);
    root->right = createFromSortedArray(arr, mid+1, j);    
    
    return root;
}


int main() {
    
    node * root = NULL;

    int arr[] = {1,2,3,4,5};
    root = createFromSortedArray(arr, 0,4);
    inorder(root); 
    cout << endl << "Height: \t" << Height(root) << endl;

}
