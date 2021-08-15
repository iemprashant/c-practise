/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head){
            return NULL;
        }
        ListNode*curr=head;
        ListNode*next=NULL;
        ListNode*prev=NULL;
        int count=1;
        while (curr != NULL && count < k) {
            curr =curr->next;
            count++;
            if(curr==NULL){
                return head;
            }
        }
        curr=head;
        count=0;
        while (count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        
        if(curr!=NULL){
            head->next=reverseKGroup(next,k);
        }
        return prev;
    }
};