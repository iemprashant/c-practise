// { Driver Code Starts
#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};



Node *swapkthnode(Node* head, int num, int K);

void addressstore(Node **arr, Node* head)
{
    Node* temp = head;
    int i = 0;
    while (temp) {
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(Node ** before, Node **after, int num, int K)
{
    if (K > num)
        return 1;
    return (before[K - 1] == after[num - K]) && (before[num - K] == after[K - 1]);
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int num, K , firstdata;
        cin >> num >> K;
        int temp;
        cin >> firstdata;
        Node* head = new Node(firstdata);
        Node* tail = head;
        for (int i = 0; i < num - 1; i++) {
            cin >> temp;
            tail->next = new Node(temp);
            tail = tail->next;
        }

        Node *before[num];
        addressstore(before, head);

        head = swapkthnode(head, num, K);

        Node *after[num];
        addressstore(after, head);

        if (check(before, after, num, K))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
}
int countnodes(Node*head){
    int count=0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    return count;
}
Node *swapkthnode(Node* head, int num, int K)
{
    int n =countnodes(head);
    //case-1 when k>n
    if(K>n){
        return head;
    }
    //case2- if x and y are same ie mid element
    if(2*K-1==n){
        return head;
    }
    //case-3 if x and y are different
    //move x pointer to the kth node from start
    Node * x=head;
    Node*xprev=NULL;
    for(int i=1;i<K;i++){
        xprev=x;
        x=x->next;
    }
    // similarly put y pointer to  kth node from last
    Node * y=head;
    Node*yprev=NULL;
     for(int i=1;i<n-K+1;i++){
        yprev=y;
        y=y->next;
    }
    //changing the previous links if exist
    if(xprev){
        xprev->next=y;
    }
    if(yprev){
        yprev->next=x;
    }
    //swap pointers of x and y
    Node*temp=x->next;
    x->next=y->next;
    y->next=temp;
    //if k=1or k=n then pointerhead change;
    if(K==1){
        head=y;
    }
    if(K==n){
        head=x; 
    }
    return head;
}
