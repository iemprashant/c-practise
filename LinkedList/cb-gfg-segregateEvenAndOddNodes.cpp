#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

class Solution {
public:
    Node* divide(int N, Node *head) {
        Node*oddhead=new Node(0);
        Node*oddlist=oddhead;
        Node*evenhead=new Node(0);
        Node*evenlist=evenhead;
        while(head!=NULL){
            if(head->data%2){
                oddlist->next=head;
                oddlist=oddlist->next;
            }
            else{
                evenlist->next=head;
                evenlist=evenlist->next;
            }
            head=head->next;
        }
        evenlist->next=oddhead->next;
        oddlist->next=NULL;
        return evenhead->next;
    }
};

int main() {
    //code
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int data;
        cin >> data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N - 1; ++i)
        {
            cin >> data;
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans);
    }
    return 0;
}
