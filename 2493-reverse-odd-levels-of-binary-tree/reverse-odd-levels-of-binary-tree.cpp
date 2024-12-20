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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root)
            return root;

        queue<TreeNode*> q;
        q.push(root);
        int levelNo = 0;

        while (!q.empty()) {
            int len = q.size();
            vector<TreeNode*>
                temp; // Temporary list for storing current level nodes.

            for (int i = 0; i < len; i++) {
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node);

                // Add children to the queue for the next level.
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            // Reverse values if the current level is odd.
            if (levelNo % 2 == 1) {
                int n = temp.size();
                for (int i = 0; i < n / 2; i++) {
                    swap(temp[i]->val, temp[n - 1 - i]->val);
                }
            }

            levelNo++; // Move to the next level.
        }
        return root;
    }
};