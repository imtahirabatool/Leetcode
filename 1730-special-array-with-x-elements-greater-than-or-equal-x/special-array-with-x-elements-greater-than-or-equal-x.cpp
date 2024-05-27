class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int x = 1; x <= n; ++x) {
            // Count elements >= x using binary search
            int count =
                n - (lower_bound(nums.begin(), nums.end(), x) - nums.begin());

            // If exactly x elements are >= x, return x
            if (count == x) {
                return x;
            }
        }

        return -1; // No such x found
    }
};