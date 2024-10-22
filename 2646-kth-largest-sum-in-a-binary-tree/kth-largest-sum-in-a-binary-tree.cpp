/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<long long> levelOrderSum(TreeNode* root) {
        vector<long long> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            long long num = 0;
            while (size--) {
                TreeNode* top = q.front();
                q.pop();

                if (top->left)
                    q.push(top->left);
                if (top->right)
                    q.push(top->right);
                num += top->val;
            }
            ans.push_back(num);
        }
        sort(ans.begin(), ans.end());
        reverse(ans.begin(), ans.end());
        return ans;
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> ans = levelOrderSum(root);
        if (k > 0 && k <= ans.size()) {
            return ans[k - 1];
        } else {
            return -1;
        }
    }
};