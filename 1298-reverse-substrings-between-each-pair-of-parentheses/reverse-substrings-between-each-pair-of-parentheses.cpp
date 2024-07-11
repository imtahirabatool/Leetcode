class Solution {
    int i = 0;

public:
    string reverseParentheses(string s) { return helper(s); }

    string helper(string& s) {
        string res;

        while (i < s.length()) {
            if (s[i] == ')') {
                i++;
                reverse(res.begin(), res.end());
                return res;
            } else if (s[i] == '(') {
                i++;
                string st = helper(s);
                res += st;
            } else {
                res += s[i];
                i++;
            }
        }
        return res;
    }
};