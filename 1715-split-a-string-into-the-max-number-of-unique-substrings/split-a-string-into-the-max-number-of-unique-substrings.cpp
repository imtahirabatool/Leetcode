class Solution {
public:
    int maxUniqueSplit(string s) {
        int res = 0;
        unordered_set<string> memo;

        function<void(int, string)> backtrack = [&](int i, string curr) {
            if (i == s.length()) {
                if (!curr.empty() && memo.find(curr) == memo.end()) {
                    res = max((int)memo.size() + 1, res);
                }
                return;
            }
            curr += s[i];

            if (memo.find(curr) == memo.end()) {
                memo.insert(curr);
                backtrack(i + 1, "");
                memo.erase(curr);
            }

            backtrack(i + 1, curr);
        };

        backtrack(0, "");

        return res;
    }
};