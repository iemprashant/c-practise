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

Node *newNode(int data)
{
	Node *temp = new Node(data);

	return temp;
}


int getLength(Node * head)
{
	if(!head){
		return 0;
	}
	int l = 1;
	Node * temp = head;
	while (temp->next != head) {
		l++;
		temp = temp->next;
	}
	return l;
}


void makeCircular(Node * head)
{
	Node * temp = head;

	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = head;
}

int main() {
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		Node *head = NULL, *tail = NULL;
		int x;
		cin >> x;
		head = new Node(x);
		tail = head;
		for (int i = 0; i < n - 1; i++)
		{
			cin >> x;
			tail -> next = new Node(x);
			tail = tail -> next;
		}


		makeCircular(head);


		cout << getLength(head);

		cout << endl;
	}
	return 0;
}  // } Driver Code Ends