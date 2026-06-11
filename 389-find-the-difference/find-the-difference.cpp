class Solution {
public:
    char findTheDifference(string s, string t) {
        int t_size = t.length();
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        int j = 0;
        for (int i = 0; i < s.length(); i++) {
            if (t[j] != s[i]) {
                return t[j];
            }
            j++;
        }
        return t[t_size - 1];
    }
};