#include<iostream> 
using namespace std; 
  
struct Node 
{ 
    int data; 
    struct Node *next; 
}; 
  
struct Node *addToEmpty(struct Node *last, int data) 
{ 
    // This function is only for empty list 
    if (last != NULL) 
      return last; 
  
    // Creating a node dynamically. 
    struct Node *temp =  
           (struct Node*)malloc(sizeof(struct Node)); 
  
    // Assigning the data. 
    temp -> data = data; 
    last = temp; 
  
    // Creating the link. 
    last -> next = last; 
  
    return last; 
} 
  
struct Node *addBegin(struct Node *last, int data) 
{ 
    if (last == NULL) 
        return addToEmpty(last, data); 
  
    struct Node *temp =  
            (struct Node *)malloc(sizeof(struct Node)); 
  
    temp -> data = data; 
    temp -> next = last -> next; 
    last -> next = temp; 
  
    return last; 
} 
  
struct Node *addEnd(struct Node *last, int data) 
{ 
    if (last == NULL) 
        return addToEmpty(last, data); 
      
    struct Node *temp =  
        (struct Node *)malloc(sizeof(struct Node)); 
  
    temp -> data = data; 
    temp -> next = last -> next; 
    last -> next = temp; 
    last = temp; 
  
    return last; 
} 
  
struct Node *addAfter(struct Node *last, int data, int item) 
{ 
    if (last == NULL) 
        return NULL; 
  
    struct Node *temp, *p; 
    p = last -> next; 
    do
    { 
        if (p ->data == item) 
        { 
            temp = (struct Node *)malloc(sizeof(struct Node)); 
            temp -> data = data; 
            temp -> next = p -> next; 
            p -> next = temp; 
  
            if (p == last) 
                last = temp; 
            return last; 
        } 
        p = p -> next; 
    }  while(p != last -> next); 
  
    cout << item << " not present in the list." << endl; 
    return last; 
  
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
  
void traverse(struct Node *last) 
{ 
    struct Node *p; 
  
    // If list is empty, return. 
    if (last == NULL) 
    { 
        cout << "List is empty." << endl; 
        return; 
    } 
  
    // Pointing to first Node of the list. 
    p = last -> next; 
  
    // Traversing the list. 
    do
    { 
        cout << p -> data << " "; 
        p = p -> next; 
  
    } 
    while(p != last->next); 
  
} 
void deleteNode(Node** head, int key)  
{ 
      
    // If linked list is empty 
    if (*head == NULL) 
        return; 
          
    // If the list contains only a single node 
    if((*head)->data==key && (*head)->next==*head) 
    { 
        free(*head); 
        *head=NULL; 
        return; 
    } 
      
    Node *last=*head,*d; 
      
    // If head is to be deleted 
    if((*head)->data==key) { 
          
        // Find the last node of the list 
        while(last->next!=*head) 
            last=last->next; 
              
        // Point last node to the next of head i.e.  
        // the second node of the list 
        last->next=(*head)->next; 
        free(*head); 
        *head=last->next; 
    } 
      
    
    while(last->next!=*head&&last->next->data!=key) { 
        last=last->next; 
    } 
      
     
    if(last->next->data==key) { 
        d=last->next; 
        last->next=d->next; 
        free(d); 
    } 
    else
        cout<<"no such keyfound"; 
    }

int main() 
{ 
    struct Node *last = NULL; 
    // int n;
    // cout<<"enter no of elements to insert in empty circular ll "<<endl;
    // cin>>n;
    // int a[n];
    // for (int i = 0; i < n; i++)
    // {   cout<<"enter the element to insert"<<endl;
    //     cin>>a[i];
    //     last = addToEmpty(last,a[i]);
    // }
    // traverse(last); 
    // int b;
    // cout<<"enter element to insert at begin"<<endl;
    // cin>>b;
    // cout<<endl;
    // last = addBegin(last,b);
    // int l;
    // cout<<"enter element to insert at last"<<endl;
    // cin>>l;
    // last = addEnd(last,l );

    // cout<<"enter the elemetn";

    int s;
    last = addToEmpty(last, 6); 
    traverse(last); 
    cout<<endl;
    last = addBegin(last, 4); 
    last = addBegin(last, 2);
    traverse(last);
    cout<<endl;  
    last = addEnd(last, 8); 
    last = addEnd(last, 12);
    traverse(last);
    cout<<endl;  
    last = addAfter(last, 10, 8); 
    cout<<endl;
    traverse(last); 
    cout<<endl;
    cout<<"enter the element to search"<<endl;
    cin>>s;
    search(last, s)? cout<<"Yes" : cout<<"No"; 
    cout<<endl;
    int d;
    cout<<"enter the element to delete"<<endl;
    cin>>d;
    deleteNode(&last, d);
    cout<<"After Deletion Linked list is: "; 
    
    traverse(last);
    cout<<endl;
    return 0; 
} 