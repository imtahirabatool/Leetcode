class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charMap;
        int startIndex = -1, maxLen = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (charMap.find(s[i]) != charMap.end()) { // if s[i] already exists
                startIndex = max(startIndex, charMap[s[i]]);
            }
            charMap[s[i]] = i; // Update index in hashmap for element

            maxLen = max(maxLen, i - startIndex);
        }
        return maxLen;
    }
};