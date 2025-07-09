class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> res(nums.size());
        int evenIdx = 0, oddIdx = 1;

        for (int num : nums) {
            if (num % 2 == 0) {     // if even
                res[evenIdx] = num; // 0
                evenIdx += 2;       // 2
            } else {
                res[oddIdx] = num; // 1
                oddIdx += 2;       // 3
            }
        }
        return res;
    }
};