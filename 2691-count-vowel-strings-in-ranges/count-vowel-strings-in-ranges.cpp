class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> pre(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i];
            int l = words[i].length();
            if ((words[i][0] == 'a' || words[i][0] == 'e' ||
                 words[i][0] == 'i' || words[i][0] == 'o' ||
                 words[i][0] == 'u') &&
                (words[i][l - 1] == 'a' || words[i][l - 1] == 'e' ||
                 words[i][l - 1] == 'i' || words[i][l - 1] == 'o' ||
                 words[i][l - 1] == 'u')) {
                pre[i + 1]++;
            }
        }

        vector<int> ans;
        for (int i = 0; i < queries.size(); i++) {
            ans.push_back(pre[queries[i][1] + 1] - pre[queries[i][0]]);
        }
        return ans;
    }
};