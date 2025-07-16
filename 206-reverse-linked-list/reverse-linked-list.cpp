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
    ListNode* reverseList(ListNode* head) {
        if(!head){
            return head;
        }
        ListNode* temp=NULL;
        ListNode* nextnode= head->next;

        while(head){
            head->next=temp;//NULL 
            temp=head;
            head=nextnode;

            if(nextnode){
                nextnode=nextnode->next;
            }
        }
        return temp;
    }
};