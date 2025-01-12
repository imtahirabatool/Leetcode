class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.length() % 2 != 0) return false; 
        
        int open = 0, close = 0;

        // Forward pass
        for (int i = 0; i < s.length(); ++i) {
            if (locked[i] == '0' || s[i] == '(') open++;
            else close++;
            
            if (close > open) return false;
        }

        open = 0, close = 0;

        // Backward pass
        for (int i = s.length() - 1; i >= 0; --i) {
            if (locked[i] == '0' || s[i] == ')') close++;
            else open++;
            
            if (open > close) return false;
        }

        return true;
    }
};
