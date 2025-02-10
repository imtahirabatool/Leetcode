class Solution {
public:
    bool isNum(char num) {
        return num >= '0' && num <= '9';
    }
    string clearDigits(string s) {
        stack<char> st;

        for (char ch : s) {
            if (isNum(ch) && !st.empty()) {
                st.pop();
            } else if (!isNum(ch)) {
                st.push(ch);
            }
        }
        // Convert stack to string (reverse order)
        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};