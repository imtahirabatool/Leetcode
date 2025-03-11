class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        int n = s.size();
        int seen[3] = {-1, -1, -1};

        for (int i = 0; i < n; i++) {
            seen[s[i] - 'a'] = i;
            count += 1 + min({seen[0], seen[1], seen[2]});
        }
        return count;
    }
};