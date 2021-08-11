
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
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

class Solution {
public:
  Node* reverseList(Node *head)
    {
        Node *current=head;
        Node *prev=NULL;
        Node *n;
        while(current!=NULL){
            // save next node
            n=current->next;
            // cureent node to previous
            current->next=prev;
            // take step forward
            prev=current;
            current=n;
        }
        head=prev;
        return head;
    }
  Node*findmid(Node*head) {
    Node*fast = head->next;
    Node*slow = head;
    while (fast != NULL && fast->next != NULL) {
      fast = fast->next->next;
      slow = slow->next;    }
    return slow;
  }
  //Function to check whether the list is palindrome.
  bool isPalindrome(Node *head)
  {
    Node*starthead=head; //copyofhead
    // find mid of list
    Node* mid = findmid(head);
    //seonf halfreversesed
    Node* endhead=reverseList(mid->next);
    //cut link of first half
    while(endhead){
      if(endhead->data!=starthead->data){
        return false;
      }
      endhead=endhead->next;
      starthead=starthead->next;
    }
    return true;
  }
};

int main()
{
  int T, i, n, l, firstdata;
  cin >> T;
  while (T--)
  {

    struct Node *head = NULL,  *tail = NULL;
    cin >> n;
    // taking first data of LL
    cin >> firstdata;
    head = new Node(firstdata);
    tail = head;
    // taking remaining data of LL
    for (i = 1; i < n; i++)
    {
      cin >> l;
      tail->next = new Node(l);
      tail = tail->next;
    }
    Solution obj;
    cout << obj.isPalindrome(head) << endl;
  }
  return 0;
}