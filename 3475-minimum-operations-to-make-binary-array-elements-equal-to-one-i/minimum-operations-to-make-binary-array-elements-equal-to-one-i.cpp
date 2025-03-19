#include <vector>

class Solution {
public:
    int minOperations(vector<int>& nums) {
        if (nums.size() < 3) {
            return (find(nums.begin(), nums.end(), 0) != nums.end()) ? -1 : 0;
        }

        int count = 0;
        for (int i = 0; i <= nums.size() - 3; i++) {
            if (nums[i] == 0) {
                nums[i] = 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                count++;
            }
        }

        return (nums[nums.size() - 2] == 1 && nums[nums.size() - 1] == 1)
                   ? count
                   : -1;
    }
};