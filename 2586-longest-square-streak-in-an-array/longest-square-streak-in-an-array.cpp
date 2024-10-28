class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int res = -1, dp[100001] = {};
        sort(nums.begin(), nums.end(), greater<int>());
        for (int num : nums) {
            dp[num] = 1;
            if (num > 316)
                continue; // largest square root given the constraints
            int square = num * num;
            if (dp[square])
                res = max(res, dp[num] += dp[square]);
        }
        return res;
    }
};