class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string str : strs) {
            string sortedStr = str;

            sort(sortedStr.begin(), sortedStr.end());
            mp[sortedStr].push_back(str);
        }
        vector<vector<string>> res;

        for (auto& pair : mp) {
            res.push_back(pair.second);
        }
        return res;
    }
};