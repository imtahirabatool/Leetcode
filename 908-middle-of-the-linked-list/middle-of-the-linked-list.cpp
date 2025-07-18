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
    ListNode* middleNode(ListNode* head) {
        if (!head) return head;

        // 1. two pointers->  slow, fast
        ListNode* slow = head;
        ListNode* fast = head;

        // 2. traverse through while loop
        // condition: fast & fast ->next
        while (fast && fast->next) {
            // 3. slow ++, fast+=2
            slow = slow->next;
            fast = fast->next->next;
        }
        // 4. return slow
        return slow;
    }
};
