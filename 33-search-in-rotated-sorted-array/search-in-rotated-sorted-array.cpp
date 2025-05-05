class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), i = 0;
        while (i < n - 1 && nums[i] < nums[i + 1]) i++;

        int low, high;
        if (target >= nums[0]) low = 0, high = i;
        else low = i + 1, high = n - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }
};