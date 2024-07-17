class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndex;
        int maxLength = 0, startIndex = -1;
        
        for (int i = 0; i < s.size(); ++i) {
            if (charIndex.find(s[i]) != charIndex.end()) {
                startIndex = max(startIndex, charIndex[s[i]]);
            }
            charIndex[s[i]] = i;
            maxLength = max(maxLength, i - startIndex);
        }
        
        return maxLength;
    }
};