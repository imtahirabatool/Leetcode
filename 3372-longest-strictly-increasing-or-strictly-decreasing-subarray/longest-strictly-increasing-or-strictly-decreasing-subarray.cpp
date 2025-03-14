class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 1, dec = 1, maxInc = 1, maxDec = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) { 
                inc++;
                dec = 1;
            } else if (nums[i] < nums[i - 1]) {
                dec++;
                inc = 1;
            } else {
                inc = dec = 1;
            }
            maxInc = max(maxInc, inc);
            maxDec = max(maxDec, dec);
        }

        return max(maxInc, maxDec);
    }
};