#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

struct Node* pairwise_swap(struct Node* head)
{
    Node*temp=head;
    while(temp &&temp->next){
        swap(temp->data,temp->next->data);
        temp=temp->next->next;
    }
    return head;
}

// { Driver Code Starts.
void printList(struct Node* node) 
{ 
    while (node!=NULL) 
    { 
        printf("%d ", (node)->data); 
        node = (node)->next; 
    } 
}

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n, l,firstdata;
        cin>>n;
        // taking first node of linked list
        cin>>firstdata;
        struct Node* head = new Node(firstdata);
        struct Node* tail = head;
        // taking remaining nodes of linked list
        for(int i = 1; i < n; i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        head =pairwise_swap(head);
        printList(head);
        cout << endl;
    }
} 