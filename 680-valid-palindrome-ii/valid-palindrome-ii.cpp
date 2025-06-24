class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        while (left <= right) {
            if (s[left] != s[right]) {
                return isPalindrom(s, left + 1, right) ||
                       isPalindrom(s, left, right - 1);
            }
            left++, right--;
        }
        return true;
    }

private:
    bool isPalindrom(string& s, int left, int right) {
        while (left <= right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++, right--;
        }
        return true;
    }
};