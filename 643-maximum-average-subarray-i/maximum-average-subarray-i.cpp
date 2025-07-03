class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;

        // sum of first window
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        double maxSum = sum;

        // Slide through array
        for (int i = k; i < nums.size(); ++i) {
            sum += nums[i] - nums[i - k]; //add right i and remove left i

            maxSum = max(sum, maxSum);
        }

        return maxSum / k;
    }
};