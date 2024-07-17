class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;

        int n = strs.size();
        if (n == 0) {
            return {};
        }

        for (int i = 0; i < n; ++i) {
            string sortedStr = strs[i];
            sort(sortedStr.begin(), sortedStr.end());

            anagramGroups[sortedStr].push_back(strs[i]);
        }

        vector<vector<string>> result;
        for (const auto& group : anagramGroups) {
            result.push_back(group.second);
        }

        return result;
    }
};