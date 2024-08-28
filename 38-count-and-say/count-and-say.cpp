class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        string s = countAndSay(n - 1);

        string temp = "";
        int count = 0;
        char ch = s[0];
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ch) {
                count++;
            }
            if (s[i] != ch) {
                temp += to_string(count) + ch;
                ch = s[i];
                count = 1;
            }
        }
        temp += to_string(count) + ch;

        return temp;
    }
};