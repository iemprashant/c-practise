// { Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

int getNthFromLast(struct Node* head, int n);

int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }

    cout<<getNthFromLast(head, k)<<endl;
    }
    return 0;
}
int getNthFromLast(Node *head, int n)
{
  // find length
  Node*temp=head;
  int len=0;
  while(temp!=NULL){
    len++;
    temp=temp->next;
  }
  // if node doesnt exist
  if(n>len){
    return -1;
  }
  // if key is in list
  int temp_pos=1;
  temp=head;
  while(temp_pos!=len-n+1 ){
    temp=temp->next;
    temp_pos++;
  }
  return temp->data;
}

