
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
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
  int T, i, n, l, k;

  cin >> T;

  while (T--) {
    struct Node *head = NULL,  *tail = NULL;

    cin >> n >> k;
    int firstdata;
    cin >> firstdata;
    head = new Node(firstdata);
    tail = head;
    for (i = 1; i < n; i++)
    {
      cin >> l;
      tail->next = new Node(l);
      tail = tail->next;
    }

    cout << getNthFromLast(head, k) << endl;
  }
  return 0;
}
int getNthFromLast(Node *head, int k)
{
  if(head==NULL){
    return -1;
  }
  int temp = 0;
  Node *fast = head;
  Node *slow = head;
  while (temp < k) {
    fast = fast->next;
    temp++;
    if(fast==NULL && temp<k){
      return -1;
    }
  }
  while(fast!=NULL){
    fast=fast->next;
    slow=slow->next;
  }
  return slow->data;
}

