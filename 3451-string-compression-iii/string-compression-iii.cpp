class Solution {
public:
    string compressedString(string word) {
        string cmp = "";
        int i = 0;

        while (i < word.size()) {
            char c = word[i];
            int count = 0;
            while (i < word.size() && word[i] == c && count < 9) {
                i++;
                count++;
            }
            cmp += to_string(count) + c;
        }
        return cmp;
    }
};