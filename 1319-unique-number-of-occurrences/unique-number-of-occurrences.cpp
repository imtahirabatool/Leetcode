class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> elementCount;
        unordered_set<int> countSet;

        for (int num : arr) {
            elementCount[num]++;
        }
        for (const auto& pair : elementCount) {
            if (countSet.find(pair.second) != countSet.end()) {
                return false;
            }
            countSet.insert(pair.second);
        }
        return true;
    }
};