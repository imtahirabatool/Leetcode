class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        unordered_map<char, int> map;
        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";

        for (char c : row1) {
            map[c] = 1;
            map[toupper(c)] = 1;
        }
        for (char c : row2) {
            map[c] = 2;
            map[toupper(c)] = 2;
        }
        for (char c : row3) {
            map[c] = 3;
            map[toupper(c)] = 3;
        }
        for (string word : words) {
            bool isValid = true;
            int row = map[word[0]];
            for (char c : word) {
                if (map[c] != row) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                res.push_back(word);
            }
        }
        return res;
    }
};
