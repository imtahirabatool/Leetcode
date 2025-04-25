class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> map;
        int n = numbers.size();

        for (int i = 0; i < n; i++) {
            int complement = target - numbers[i];
            if (map.count(complement)) {
                return {map[complement] + 1, i + 1};
            }
            map[numbers[i]] = i;
        }

        return {-1, -1};
    }
};
