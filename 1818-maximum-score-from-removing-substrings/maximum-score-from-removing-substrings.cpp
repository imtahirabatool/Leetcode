class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int count = 0;
        stack<char> st;

        for (char c : s) {
            if (!st.empty() && ((st.top() == 'a' && c == 'b' && x >= y) ||
(st.top() == 'b' && c == 'a' && y > x))) {
                if ((st.top() == 'a' && c == 'b' && x >= y) ||
                    (st.top() == 'b' && c == 'a' && y > x)) {
                    st.pop();
                    count += max(x, y);
                } else {
                    st.push(c);
                }
            } else {
                st.push(c);
            }
        }

        string remaining;
        while (!st.empty()) {
            remaining.push_back(st.top());
            st.pop();
        }
        reverse(remaining.begin(), remaining.end());

        for (char c : remaining) {
            if (!st.empty() && ((st.top() == 'a' && c == 'b' && x < y) ||
                                (st.top() == 'b' && c == 'a' && y <= x))) {
                if ((st.top() == 'a' && c == 'b' && x < y) ||
                    (st.top() == 'b' && c == 'a' && y <= x)) {
                    st.pop();
                    count += min(x, y);
                } else {
                    st.push(c);
                }
            } else {
                st.push(c);
            }
        }

        return count;
    }
};
