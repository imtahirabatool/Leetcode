class Solution {
public:
    int maxVowels(string s, int k) {
        int maxCount = 0, count = 0;

        for (int i = 0; i < k; i++) { //count vowels in 1st window
            if (isVowel(s[i])) count++;
        }
        maxCount = count;

        // Slide the window
        for (int i = k; i < s.length(); i++) {
            if (isVowel(s[i - k])) count--; //then remove leftmost
            if (isVowel(s[i])) count++; // and add rightmost

            maxCount = max(count, maxCount);
        }
        return maxCount;
    }

private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};