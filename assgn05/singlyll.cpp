#include<iostream>

using namespace std;


class Node  
{  
    public: 
    int data;
      
    Node *next;  
}; 
void push(Node** head_ref, int new_data)  
{  
   
    Node* new_node = new Node();  
  
    
    new_node->data = new_data;  
  
   
    new_node->next = (*head_ref);  
  
   
    (*head_ref) = new_node;  
} 
void printList(Node *node)  
{  
    while (node != NULL)  
    {  
        cout<<" "<<node->data;  
        node = node->next;  
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
void deleteNode(struct Node **head_ref, int key) 
{ 
    // Store head node 
    struct Node* temp = *head_ref, *prev; 
  
    
    if (temp != NULL && temp->data == key) 
    { 
        *head_ref = temp->next;   // Changed head 
        free(temp);               // free old head 
        return; 
    } 
  
    
    while (temp != NULL && temp->data != key) 
    { 
        prev = temp; 
        temp = temp->next; 
    } 
  
    // If key was not present in linked list 
    if (temp == NULL) return; 
  
    // Unlink the node from linked list 
    prev->next = temp->next; 
  
    free(temp);  
}    
int main()
{   int n;
    Node* head = NULL;
    cout<<"enter no of elements to insert "<<endl;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {   cout<<"enter the element to insert"<<endl;
        cin>>a[i];
        push(&head,a[i]);
    }
    
   
    cout<<"Created Linked list is: ";  
    printList(head);
    
    cout<<endl;
    int s;
    cout<<"enter the element to search"<<endl;
    cin>>s;
    search(head, s)? cout<<"Yes" : cout<<"No"; 
    cout<<endl;
    int d;
    cout<<"enter the element to delete"<<endl;
    cin>>d;
    deleteNode(&head, d);
    cout<<"After Deletion Linked list is: "; 
    printList(head);
    cout<<endl;
      
    return 0;  

}