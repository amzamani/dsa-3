#include<iostream> 

using namespace std; 
  
struct node 
{ 
    int key; 
    struct node *left, *right; 
}; 
  

struct node *newNode(int item) 
{ 
    struct node *temp = (struct node *)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  

void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        cout<<  root->key<<endl;
        inorder(root->right); 
    } 
} 
  
struct node* insert(struct node* node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->key) 
        node->left = insert(node->left, key); 
    else
        node->right = insert(node->right, key); 
  
    
    return node; 
} 
  

struct node * minValueNode(struct node* node) 
{ 
    struct node* current = node; 
  
    
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 
  

struct node* deleteNode(struct node* root, int key) 
{ 
    // base case 
    if (root == NULL) return root; 
  
  
    if (key < root->key) 
        root->left = deleteNode(root->left, key); 
  
    else if (key > root->key) 
        root->right = deleteNode(root->right, key); 
  
    
    else
    { 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        struct node* temp = minValueNode(root->right); 
  
        // Copy the inorder successor's content to this node 
        root->key = temp->key; 
  
        // Delete the inorder successor 
        root->right = deleteNode(root->right, temp->key); 
    } 
    return root; 
} 
  
int main() 
{ 
   
    struct node *root = NULL; 
    
    int ch, val,val2;
    cout << "1)Insert\n";
    cout << "2)Delete\n";
    cout << "3)Display\n";
    cout << "4)Exit\n";
    do
    {

        cout << "Enter choice : " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Input for insertion: " << endl;
            cin >> val;
            root = insert(root, val);
            break;
        case 2:
            cout << "element for deletion: " << endl;
            cin >> val2;
            deleteNode(root, val2);
            break;
        case 3:
            cout<<"Inorder traversal of the modified tree \n"; 
            inorder(root);
            
            break;
        case 4:
            cout << "Exit\n";
            break;
        default:
            cout << "Incorrect!\n";
        }

        
    } while (ch != 4);
    return 0;
} 