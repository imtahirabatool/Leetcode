class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s); // split words as ["Hello", "World"]
        string word;
        vector<string> words;
        // Step:1 split words and store them in words
        while (ss >> word) {
            words.push_back(word);
        }

        // Step:2 push those words in reverse order
        string res;
        for (int i = words.size() - 1; i >= 0; i--) {
            res += words[i];
            if (i != 0) {
                res += " ";
            }
        }

        return res;
    }
};