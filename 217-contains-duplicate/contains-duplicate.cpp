class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;

        for (int num : nums) {
            map[num]++;
        }

        for (const auto& mp : map) {
            if (mp.second > 1) {
                return true;
            }
        }
        return false;
    }
};