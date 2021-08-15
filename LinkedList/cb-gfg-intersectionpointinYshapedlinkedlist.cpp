
#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

int countnodes(Node* head){
    int cnt=1;
    while(head->next!=NULL){
        head=head->next;
        cnt++;
    }
    return cnt;
}
Node* movesteps(Node * head,int k){
    while(k--){
        head=head->next;
    }
    return head;
}
int intersectPoint(Node* head1, Node* head2)
{
    int n1=countnodes(head1);
    int n2=countnodes(head2);
    if(n1>n2){
        head1=movesteps(head1,abs(n1-n2));
    }
    else{
        head2=movesteps(head2,abs(n1-n2));
    }
    while(head1!=head2){
        head2=head2->next;
        head1=head1->next;
    }
    return head2->data;

}

