// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    struct Node *next;
    
    Node(int x) {
        data = x;
        next = NULL;
    }
};

void display(Node* head)
{
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout<<endl;
}

Node* insertInMiddle(Node* head, int x);

int main()
{
    int T, n, x;
    cin>>T;
    while(T--)
    {
        cin>> n >> x;
        
        struct Node *head = new Node(x);
        struct Node *tail = head;
        
        for (int i=0; i<n-1; i++)
        {
            cin>>x;
            tail->next = new Node(x);
            tail = tail->next;
        }
        
        cin>> x;
        head = insertInMiddle(head, x);
        display(head);
    }
    return 0;
}

Node* insertInMiddle(Node* head, int x)
{
    int countnodes=0;
    Node *temp=head;
    while(temp!=NULL){
        temp=temp->next;
        countnodes++;
    }
    int mid=(countnodes+1)/2;
    temp=head;
    int pos=1;
    while(mid!=pos){
        temp=temp->next;
        pos++;
    }
    Node *n=new Node(x);
    n->next=temp->next;
    temp->next=n;
    return head;
}