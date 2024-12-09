class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        int m = queries.size();
        vector<bool> ans(m);

        int n = nums.size();
        vector<int> prefix(n, 0);

        for (int i = 1; i < n; i++) {
            if (nums[i] % 2 == nums[i - 1] % 2) {
                prefix[i] = 1 + prefix[i - 1];
            } else {
                prefix[i] = prefix[i - 1];
            }
        }

        for (int i = 0; i < m; i++) {
            int s = queries[i][0];
            int e = queries[i][1];
            ans[i] = (prefix[e] - prefix[s] == 0);
        }

        return ans;
    }
};