class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> res(nums.size());
        int evenIndex = 0;
        int oddIndex = 1;

        for (int num : nums) {
            if (num % 2 == 0) {
                res[evenIndex] = num;
                evenIndex += 2;
            } else {
                res[oddIndex] = num;
                oddIndex += 2;
            }
        }

        return res;
    }
};