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

void print(Node *root)
{
	Node *temp = root;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}


class Solution
{
public:
	//Function to remove duplicates from unsorted linked list.
	Node * removeDuplicates( Node *head)
	{
		set<int> s;
		Node*temp = head;
		Node*prev = NULL;
		while (temp != NULL) {
			if (s.find(temp->data) == s.end()) {
				//element is not in set,fill the value in set as its first encountered
				s.insert(temp->data);
				prev = temp;

			}
			else {
				prev->next = temp->next;
				delete temp;
			}
			temp = prev->next;
		}
		return head;
	}
};


// { Driver Code Starts.

int main() {
	// your code goes here
	int T;
	cin >> T;

	while (T--)
	{
		int K;
		cin >> K;
		struct Node *head = NULL;
		struct Node *temp = head;

		for (int i = 0; i < K; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		Solution ob;
		Node *result  = ob.removeDuplicates(head);
		print(result);
		cout << endl;

	}
	return 0;
}