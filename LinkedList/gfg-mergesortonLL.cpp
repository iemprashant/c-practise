// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
public:
    Node * getMiddle(Node *head)
    {
        Node*fast = head->next;//to handle only 2 elemts case
        Node*slow = head;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    Node* sortedMerge(Node* head1, Node* head2)
    {

        if (head1 == NULL) {
            return head2;
        }
        if (head2 == NULL) {
            return head1;
        }
        Node*c = NULL;
        if (head1->data <= head2->data) {
            c = head1;
            c->next = sortedMerge(head1->next, head2);
        }
        else {
            c = head2;
            c->next = sortedMerge(head1, head2->next);
        }
        return c;
    }
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        //rec casse
        //break perperation
        Node *mid = getMiddle(head);
        Node *a = head;
        Node *b = mid->next;
        //break about mid;
        mid->next=NULL;

        a = mergeSort(a);
        b = mergeSort(b);
        Node *c= sortedMerge(a,b);
        return c;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends