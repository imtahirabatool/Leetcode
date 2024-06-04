class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char> charSet;
        int count = 0;
        
        for (char c : s) {
            if (charSet.find(c) != charSet.end()) {
                charSet.erase(c);
                count += 2;
            } else {
                charSet.insert(c);
            }
        }
        if (!charSet.empty()) {
            count += 1;
        }
        return count;
    }
};