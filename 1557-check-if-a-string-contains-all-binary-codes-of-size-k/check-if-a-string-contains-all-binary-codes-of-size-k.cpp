class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> set;

        if (s.length() < k) return false;

        for (int i = 0; i <= s.length() - k; i++) {
            set.insert(s.substr(i, k));
        }

        return set.size() == (1 << k);
    }
};