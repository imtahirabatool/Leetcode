class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int count = 0, left = 0;
        int product = 1;

        for (int right = 0; right < nums.size(); right++) {
            product *= nums[right];

            while (product >= k && left <= right) {
                product /= nums[left];
                left++;
            }
            
            // all subarrays ending at right and starting from left to right
            count += (right - left + 1);
        }
        return count;
    }
};
