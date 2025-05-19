class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0, n = nums.size();
        int maxi = nums.back();

        if (maxi < nums.size())
            res++;
        if (nums[0] != 0 && maxi < nums.size())
            res++;

        for (int i = 0; i < n; i++) {
            if (i + 1 > nums[i] && i + 1 < nums.back() && i + 1 < nums[i + 1])
                res++;
        }
        return res;
    }
};