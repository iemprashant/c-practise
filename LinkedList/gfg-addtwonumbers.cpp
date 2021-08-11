// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin >> val;

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

class Solution
{
public:
    Node *rotatelist(Node* head) {
        if (!head->next) {
            return head;
        }
        Node*newnode = rotatelist(head->next);
        Node *temp = head->next;
        temp->next = head;
        temp->next->next = NULL;

        return newnode;
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        //revre the original head
        first = rotatelist(first);
        second = rotatelist(second);
        // copy of head for working
        Node* firsthead = first;
        Node* secondhead = second;
        Node*prev = NULL;
        int carry = 0;
        while (firsthead && secondhead) {
            int sum = firsthead->data + secondhead->data + carry;
            firsthead->data = sum % 10;
            carry = sum / 10;
            prev = firsthead;
            firsthead = firsthead->next;
            secondhead = secondhead->next;
        }
        if (firsthead || secondhead) {
            if (secondhead) {
                prev->next = secondhead;

            }
            //iffirst list has element then prev->next is already on list 1
            //new head for both link as pe need
            Node*temphead = prev->next;
            while (temphead) {
                int temp = temphead->data + carry;
                temphead->data = temp % 10;
                carry = temp / 10;
                prev = temphead;
                temphead = temphead->next;
            }

        }
        if (carry > 0) {
            prev->next = new Node(carry);
        };

        return rotatelist(first);
    }
};


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;

        cin >> n;
        Node* first = buildList(n);

        cin >> m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first, second);
        printList(res);
    }
    return 0;
}