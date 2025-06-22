class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> res(nums.size());
        int evenIdx = 0, oddIdx = 1;

        for (int num : nums) {
            if (num % 2 == 0) {
                res[evenIdx] = num;
                evenIdx += 2;
            } else {
                res[oddIdx] = num;
                oddIdx += 2;
            }
        }

        return res;
    }
};