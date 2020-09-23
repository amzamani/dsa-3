#include<iostream>

using namespace std;


class Node  
{  
    public: 
    int data;
      
    Node *next; 
    Node *prev; 
}; 

void push(struct Node** head_ref, int new_data) 
{ 
    
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
  
   
    new_node->data = new_data; 
  
   
    new_node->next = (*head_ref); 
    new_node->prev = NULL; 
  
    
    if ((*head_ref) != NULL) 
        (*head_ref)->prev = new_node; 
  
    
    (*head_ref) = new_node; 
}
// void deleteNode(struct Node **head_ref, int key) 
// { 
//     // Store head node 
//     struct Node* temp = *head_ref, *prev; 
  
//     // If head node itself holds the key to be deleted 
//     if (temp != NULL && temp->data == key) 
//     { 
//         *head_ref = temp->next;   // Changed head 
//         free(temp);               // free old head 
//         return; 
//     } 
  
    
//     while (temp != NULL && temp->data != key) 
//     { 
//         prev = temp; 
//         temp = temp->next; 
//     } 
  
//     // If key was not present in linked list 
//     if (temp == NULL) return; 
  
//     // Unlink the node from linked list 
//     prev->next = temp->next; 
  
//     free(temp);  
// } 

void deleteNode(struct Node** head_ref, struct Node* del) 
{ 
    /* base case */
    if (*head_ref == NULL || del == NULL) 
        return; 
  
    
    if (*head_ref == del) 
        *head_ref = del->next; 
  
    
    if (del->next != NULL) 
        del->next->prev = del->prev; 
  
   
    if (del->prev != NULL) 
        del->prev->next = del->next; 
  
    
    free(del); 
    return; 
} 
void printList(struct Node* node)  
{  
    struct Node* last;  
    printf("\nTraversal in forward direction \n");  
    while (node != NULL) {  
        printf(" %d ", node->data);  
        last = node;  
        node = node->next;  
    }  
  
    printf("\nTraversal in reverse direction \n");  
    while (last != NULL) {  
        printf(" %d ", last->data);  
        last = last->prev;  
    }  
} 
bool search(Node* head, int x)  
{  
    Node* current = head; // Initialize current  
    while (current != NULL)  
    {  
        if (current->data == x)  
            return true;  
        current = current->next;  
    }  
    return false;  
}
int main()  
{  
    /* Start with the empty list */
    // struct Node* head = NULL;  

    // push(&head, 7);  
  
    // push(&head, 1);  
  
    // push(&head, 4);  
  
    // Insert 8, before 1. So linked list becomes 4->8->1->7->NULL  

    int n;
    Node* head = NULL;
    cout<<"enter no of elements to insert "<<endl;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {   cout<<"enter the element to insert"<<endl;
        cin>>a[i];
        push(&head,a[i]);
    }
    
    int d;
    cout<<"Created Doubly Linked list is: ";  
    printList(head);
    cout<<endl;
    int s;
    cout<<"enter the element to search"<<endl;
    cin>>s;
    search(head, s)? cout<<"Yes" : cout<<"No"; 
    cout<<endl;
    cout<<"enter the element to delete"<<endl;
    cin>>d;
    deleteNode(&head, head->next);
    cout<<"After Deletion Linked list is: "; 
    printList(head);
    cout<<endl;
  
    cout<<endl;

    getchar();  
    return 0;  
}  