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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> res;
        ListNode* prev = head;
        ListNode* curr = head->next;
        int ind = 2;
        while (curr->next) {
            if (curr->val > prev->val && curr->val > curr->next->val) {
                res.push_back(ind);
            } else if (curr->val < prev->val && curr->val < curr->next->val) {
                res.push_back(ind);
            }
            prev = curr;
            curr = curr->next;
            ind++;
        }
        if (res.size() < 2) {
            return {-1, -1};
        }
        int maxi = res.back() - res[0];
        int mini = INT_MAX;
        for (int i = 1; i < res.size(); i++) {
            mini = min(mini, res[i] - res[i - 1]);
        }
        return {mini, maxi};
    }
};