// Program for Binary Search Trees
#include<iostream>
#include<queue>

using namespace std;

typedef struct BSTNode {
    int data;
    BSTNode *left;    
    BSTNode *right;    
} BSTNode;



BSTNode* getNode(int value) {
   BSTNode* temp = new BSTNode();     
   temp->data = value;
   temp->right = NULL;
   temp->left = NULL;
   return temp; 
}


void Insert (BSTNode** root, int value) {
   // If root is NULL
   if (*root == NULL) {
       *root = getNode(value);
   }
   else {
       if(value <= (*root)->data) { 
            // Insert into the left subtree    
            Insert( &((*root)->left), value);
       }    
       else {
            // Insert into right subtre
            Insert( &((*root)->right), value);
       }
   }
   return; 
}

int Height(BSTNode* root) {
    
    if (root == NULL) {
        // Could be child of a leaf
        return -1; 
    }

    // Leaf
   // else if ( root->left == NULL && root->right == NULL )
     //   return 0;

    else
        return 1 + max( Height(root->left), Height(root->right));
}

// Levelwise traversal
void BFS(BSTNode* root) {
    if (root == NULL) return;
    int i = 0; 
    queue<BSTNode*> q;
    q.push(root);
    cout << endl << "Level order Traversal is:" << endl;
    while(!q.empty()){
        BSTNode* temp = q.front();
        cout << "\t" << temp->data;
        if (temp->left != NULL) { 
            q.push(temp->left);
        }
        if (temp->right != NULL) {
            q.push(temp->right);
        }
        q.pop();
    }
}


// Preorder Traversal of the binary tree
void Preorder(BSTNode* root) {
    if (root == NULL) return;
    cout << "\t" << root->data;
    Preorder(root->left);
    Preorder(root->right);
}

// Inorder Traversal of the binary tree
void Inorder(BSTNode* root) {
    if (root == NULL) return;
    Inorder(root->left);
    cout << "\t" << root->data;
    Inorder(root->right);
}

// Postorder Traversal of the binary tree
void Postorder(BSTNode* root) {
    if (root == NULL) return;
    Postorder(root->left);
    Postorder(root->right);
    cout << "\t" << root->data;
}

bool Search(BSTNode **root, int value) {
    if(*root == NULL){
        return false;    
    }

    else if( (*root)->data == value) {
        return true;    
    }

    else if( value <= (*root)->data) {
        return Search( &((*root)->left), value);    
    } 
      
    else if( value > (*root)->data) {
        return Search( &((*root)->right), value);    
    }

    return false;
}

/*
int FindMin(BSTNode** root) {
    
    if(root==NULL) return -1;
     
    if((*root)->left == NULL) 
        return (*root)->data;
    else
        return FindMin(&((*root)->left));
}
*/

int FindMin(BSTNode** root) {
    
    BSTNode *curr = *root;
    if (curr == NULL) return -1;
    while(curr->left != NULL) {
        curr = curr->left;    
    }
    return curr->data;
}

int main() {
    
    BSTNode * root; 
    root = NULL;    
    /*
    Insert(&root, 10);
    Insert(&root, 5);
    Insert(&root, 12);
    Insert(&root, 34);
    Insert(&root, 54);
    Insert(&root, 12);
    Insert(&root, 245);
    Insert(&root, 280);
    Insert(&root, 66);
    Insert(&root, 234);
    Insert(&root, 1);

    */

    int i = 0;
    for(i=0; i< 100; i++) {
        Insert(&root, rand()%50000);
    }
    cout << endl << "Minimum Value is \t" << FindMin(&root);   
    cout << endl << "Height is \t" << Height(root);   
    cout << endl;
    
    BFS(root);

    cout << endl << "Preorder Traversal:" << endl;
    Preorder(root); 
    cout << endl;
    
    cout << endl << "Inorder Traversal:" << endl;
    Inorder(root); 
    cout << endl;

    cout << endl << "Postorder Traversal:" << endl;
    Postorder(root); 
    cout << endl;
}
