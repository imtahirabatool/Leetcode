class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int res=0;

        for (int num : set) {
            if (!set.count(num - 1)) {
                int currNum = num, currStreak = 1;

                while (set.count(currNum + 1)) {
                    currNum++;
                    currStreak++;
                }
                res = max(res, currStreak);
            }
        }

        return res;
    }
};