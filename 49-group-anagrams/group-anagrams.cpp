class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>anagramGroup;

        int n=strs.size();
        if(n==0)return {};

        for(int i=0; i<n; ++i){
            string sortedStr=strs[i];
            sort(sortedStr.begin(), sortedStr.end());

            anagramGroup[sortedStr].push_back(strs[i]);
        }

        vector<vector<string>>res;
        for(const auto& group:anagramGroup){
            res.push_back(group.second);
        }

        return res;
    }
};