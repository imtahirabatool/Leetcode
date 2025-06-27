class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length(), len2 = s2.length();

        if (len1 > len2) return false;

        sort(s1.begin(), s1.end());// so that sep. perm na lenii paray

        for (int i = 0; i <= len2 - len1; i++) {
            string window = s2.substr(i, len1);// s1 kii length k substr ki window

            sort(window.begin(), window.end());

            if (window == s1) return true;
        }
        return false;
    }
};