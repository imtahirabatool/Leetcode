class Solution {
public:
    bool isZeroArray(int m, vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);

        for (int i = 0; i < m; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];

            diff[l] += val;

            if (r + 1 < n)
                diff[r + 1] -= val;
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            result += diff[i];
            if (nums[i] > result)
                return false;
        }

        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int l = 0, r = queries.size();
        int result = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isZeroArray(mid, nums, queries)) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return result;
    }
};