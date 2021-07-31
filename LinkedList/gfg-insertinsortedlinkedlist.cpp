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


Node * insertInSorted(Node * head, int data)
{
    // head insertion
    Node *n = new Node(data);
    if (head->data > data) {
        n->next = head;
        head = n;
        return head;
    }
    //mid or tail insertion
    Node*temp = head;
    while ( temp->next != NULL  &&  temp->next->data < data)
    {
        temp = temp->next;
    }
    n->next = temp->next;
    temp->next = n;
    return head;
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
        cin >> data;
        head = insertInSorted(head, data);
        displayList (head);
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends