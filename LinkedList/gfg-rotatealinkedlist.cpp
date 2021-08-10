// { Driver Code Starts
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


class Solution
{
public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        if (k == 0)
            return head;
        Node*temp = head;
        //make list circular
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = head;

        //move to k-1 break link and updat kth to new head
        Node* current=head;
        for (int i=0;i<k-1;i++) { //k-1 to stop one step prev
            current = current->next;
        }
        head=current->next;
        current->next=NULL;
        return head;
    }
};

void printList(Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, val, k;
        cin >> n;

        cin >> val;
        Node *head = new Node(val);
        Node *tail = head;

        for (int i = 0; i < n - 1; i++)
        {
            cin >> val;
            tail->next = new Node(val);
            tail = tail->next;
        }

        cin >> k;

        Solution ob;
        head = ob.rotate(head, k);
        printList(head);
    }
    return 1;
}