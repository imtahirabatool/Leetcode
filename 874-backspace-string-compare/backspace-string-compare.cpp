class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> stackS;
        stack<char> stackT;
        for (auto ch : s) {
            if (ch != '#')
                stackS.push(ch);
            else if (!stackS.empty())
                stackS.pop();
        }

        for (auto ch : t) {
            if (ch != '#')
                stackT.push(ch);
            else if (!stackT.empty())
                stackT.pop();
        }
        return stackS == stackT;
    }
};