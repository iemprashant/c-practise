
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


Node * deleteAtPosition(Node *head, int pos)
{
    Node*temp = head;
    // if delete at head
    if (pos == 1) {
        head = head->next;
        delete temp;
        return head;
    }
    else {
        int temp_pos = 1;
        while (temp->next != NULL && temp_pos != pos - 1) {
            temp = temp->next;
            temp_pos++;
        }
        // if pos is more than the list size
        if (temp->next == NULL) {
            return head;;
        }
        // delete in mid
        Node*pos_element = temp->next;
        temp->next = pos_element->next;
        delete pos_element;
        return head;
    }

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
        int pos;
        cin >> pos;
        head = deleteAtPosition(head, pos);
        displayList(head);
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends