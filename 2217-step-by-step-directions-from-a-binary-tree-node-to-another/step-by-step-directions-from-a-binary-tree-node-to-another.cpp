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
    bool getPath(TreeNode* root, int value, string& path) {
        if (!root) return false;
        if (root->val == value) return true;
        path.push_back('L');
        if (getPath(root->left, value, path)) return true;
        path.pop_back();
        path.push_back('R');
        if (getPath(root->right, value, path)) return true;
        path.pop_back();
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string pathToStart, pathToDest;
        getPath(root, startValue, pathToStart);
        getPath(root, destValue, pathToDest);

        int i = 0;
        while (i < pathToStart.size() && i < pathToDest.size() && pathToStart[i] == pathToDest[i]) {
            i++;
        }

        string result(pathToStart.size() - i, 'U');
        result += pathToDest.substr(i);
        return result;
    }
};