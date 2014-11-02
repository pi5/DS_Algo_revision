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

// This implementation touches each node once per every node above it. 
// Hence the complexity is O(N log N)
bool isBalancedSimple (node* root) {
    if(root == NULL) return true;

    int r = Height(root->right);
    int l = Height(root->left);

    return ( (abs(r-l) <= 1 && isBalancedSimple(root->right) && isBalancedSimple(root->left)));
}


int checkHeight(node* root) {
    // Base case
    if (root == NULL) return 0;    
    
    int leftHeight = checkHeight(root->left);
    if (leftHeight == -1) return -1;

    int rightHeight = checkHeight(root->right);
    if(rightHeight == -1) return -1;

    int diff = abs(leftHeight - rightHeight);
    if(diff > 1) {
        return -1;
    }
    else {
        return max(leftHeight, rightHeight) + 1;    
    }
}

// This is optimized version of checkHeight
// The complexity is O(N) since each node is visited only once
// The height is passed along progressively
bool isBalancedOptimized(node* root) {
    if (checkHeight(root) == -1) return false;
    else return true;
}


int main() {

    node *root = NULL;
    //cout << "\nb1\n" << endl;
    root = insert(root, 5);    
    root = insert(root, 7);    
    root = insert(root, 3);    
    //root = insert(root, 2);    
    //root = insert(root, 4);
    root = insert(root, 8);    
    //root = insert(root, 6);
    inorder(root); 
    cout << endl << "Height: \t" << Height(root) << endl;
    cout << endl << "isBalancedSimple: \t" << isBalancedSimple(root) << endl;
    cout << endl << "isBalancedOptimized: \t" << isBalancedOptimized(root) << endl;

}
