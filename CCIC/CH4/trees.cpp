#include<iostream>
#include<iomanip>
using namespace std;

typedef struct node {

    int value;
    node* left; 
    node* right;
    node* parent;    

} node;


node* getNode(int value) {
    node* temp = new node();
    temp->value = value;
    temp->right = temp->left = temp->parent = NULL;
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
            (root->left)->parent = root;  
        }
        else{
            root->right = insert(root->right, value);    
            (root->right)->parent = root;
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

bool checkBST(node* root, int min, int max){
    
    if (root == NULL) return true;
    int value = root->value;
    
    if (value < min || value >= max) return false;
    
    return checkBST(root->left, min, value) && checkBST(root->right, value, max);
    
}

bool checkBST(node* root) {
    int max = 99999;
    int min = -99999;
    return checkBST(root, min, max);
}


void insertLeftmost(node*root, int value) {
    if (root == NULL) return;
    while(root->left != NULL) root = root->left;    
    root->left = getNode(value);
    (root->left)->parent = root;
}


node* leftmostChild(node* n) {
    if (n == NULL) return NULL;
    while(n->left!=NULL) n = n->left;
    return n;    
}

node* inorderSuccessor (node* n) {
    if (n == NULL) return NULL;
    
    if(n->right != NULL) {
        return leftmostChild(n->right);
    }
    else {
        node* q = n;
        node* p = q->parent;
        
        while(p != NULL && p->right == q) {
            q = p; //q->parent;
            p = q->parent;    
        } 
        return p;   
    }
}

bool covers(node* root, node* p) {
    if (root == NULL) return false;
    if (root == p) return true;
    
    return covers(root->left, p) || covers(root->right, p);    
}

node* firstCommonAncestor(node* root, node* p, node* q) {
    if(root == NULL) return NULL;    
    if (root == p || root == q) return root;

    bool p_on_left = covers(root->left, p);
    bool q_on_left = covers(root->left, q);
    
    // if they are on the same side
    if (p_on_left != q_on_left) return root;
    else{
        if(p_on_left) return firstCommonAncestor(root->left, p, q);
        else return firstCommonAncestor(root->right, p, q);    
    }
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
    cout << endl << "Height: \t" << Height(root) << endl;
    cout << endl << "isBalancedSimple: \t" << isBalancedSimple(root) << endl;
    cout << endl << "isBST: \t" << checkBST(root) << endl;

    insertLeftmost(root, -1);
    cout << endl << "isBST: \t" << checkBST(root) << endl;

    node* l = root;
    node* ios = inorderSuccessor(l);

    inorder(root);
    if(ios!=NULL) 
        cout << endl << "Inorder successor or " << l->value << " is: " << ios->value << endl;


    node *a = root->left;
    node *b = leftmostChild(root);
    node *c = firstCommonAncestor(root, a, b);
    cout << endl << "firstCommonAncestor of " << a->value << " and " << b->value << " is " << c->value << endl;
}
