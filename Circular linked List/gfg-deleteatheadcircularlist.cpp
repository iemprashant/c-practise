
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node (int x)
    {
        data=x;
        next=NULL;
    }
        
};

Node *newNode(int data)
{
    Node *temp=new Node(data);
    
    return temp;
}



void displayList(Node *head)
{
    Node *temp=head;
    while(temp->next!=head)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data<<" ";
}



int getLength(Node * head)
{
    Node *temp=head;
    
    int count=0;
    while(temp->next!=head)
    {
        count++;
        temp=temp->next;
    }
    return count+1;
}

Node * deleteHead(Node *head)
{
   Node * tail=head;
   while(tail->next!=head){
   	tail=tail->next;
   }
   Node *newhead=head->next;
   head->next=NULL;
   tail->next=newhead;
   return newhead;
}


void makeCircular(Node * head)
{
    Node * temp=head;
    
    while(temp->next)
    {
        temp=temp->next;
    }
    temp->next=head;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    Node *head=NULL, *tail = NULL;
	    int x;
	    cin >> x;
	    head = new Node(x);
	    tail = head;
	    for(int i=0;i<n-1;i++)
	    {
	        cin>>x;
	        tail -> next = new Node(x);
	        tail = tail -> next;
	    }
	    
  

	    makeCircular(head);
	    
	    Node * oldHead=head;
	    head=deleteHead(head);
	    
	    if(oldHead->next==NULL)
	    {
	    
    	    displayList(head);
	    }
	    else
	    {
	        cout<<"Please set the next of original head to null";
	    }

	    
	 
	    
	    cout<<endl;
	}
	return 0;
}  // } Driver Code Ends