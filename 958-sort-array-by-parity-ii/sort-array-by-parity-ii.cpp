class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> res;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                res.push_back(nums[i]);
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 != 0) {
                res.push_back(nums[i]);
            }
        }
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            ans.push_back(res[left]);
            ans.push_back(res[right]);
            left++;
            right--;
        }
        return ans;
    }
};