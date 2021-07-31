// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node (int x)
    {
        data = x;
        next = NULL;
    }

};


void displayList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
}



// } Driver Code Ends
//User function Template for C++

/*
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
*/

bool isSorted(Node * head)
{

    if (head == NULL) {
        return true;
    }
    int pos = 0;
    int neg = 0;
    while (head->next != NULL) {
        if ((head->next->data) - (head->data) > 0 ) {
            pos++;
        } 
        if ((head->next->data) - (head->data) < 0 ) {
            neg--;
        }
        head = head->next;
    }
    if (pos != 0 && neg != 0) {
        return false;
    }
    return true;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int data;
        cin >> data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < n - 1; ++i)
        {
            cin >> data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        cout << isSorted(head) << endl;
    }
    return 0;
}  // } Driver Code Ends