class Solution {
public:
    int countGoodSubstrings(string s) {
        int k=3, count=0;
        
        if (s.length() < k) return 0; 
        
        for (int i = 0; i <= s.length() - k; i++) {
            if(isUnique(s[i], s[i+1], s[i+2]))count++;
        }
        return count;
    }

private:
    bool isUnique(char a, char b, char c) {
        return a != b && b != c && c != a;
    }
};