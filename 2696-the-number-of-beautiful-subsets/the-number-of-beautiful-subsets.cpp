class Solution {
public:
    void solve(vector<int>& nums, int index, int k, unordered_map<int, int>& freq, int& count) {
        // Base case: if we've considered all elements
        if (index == nums.size()) {
            count++;  // Every path to this point is a valid subset
            return;
        }

        // Exclude the current element and move to the next
        solve(nums, index + 1, k, freq, count);
        
        // Check if we can include nums[index] in the subset
        bool canInclude = true;
        if (freq[nums[index] - k] > 0 || freq[nums[index] + k] > 0) {
            canInclude = false;
        }

        // Include the current element if it's valid
        if (canInclude) {
            freq[nums[index]]++;
            solve(nums, index + 1, k, freq, count);
            freq[nums[index]]--;  // Backtrack
        }
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int count = 0;
        solve(nums, 0, k, freq, count);
        return count - 1; // Subtract 1 to exclude the empty subset
    }
};