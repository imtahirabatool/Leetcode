class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> sm;
        vector<int> eq;
        vector<int> lrg;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < pivot) {
                sm.push_back(nums[i]);
            } else if (nums[i] > pivot) {
                lrg.push_back(nums[i]);
            } else {
                eq.push_back(nums[i]);
            }
        }

        for (int i = 0; i < eq.size(); i++) {
            sm.push_back(eq[i]);
        }
        for (int i = 0; i < lrg.size(); i++) {
            sm.push_back(lrg[i]);
        }

        return sm;
    }
};