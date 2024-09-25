class Solution {
public:
    struct TrieNode {
        int count = 0;
        TrieNode* children[26] = {nullptr};  // Array to store references to child nodes
    };
    
    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode* root = new TrieNode();
        
        // Build the Trie and count the occurrences of each prefix
        for (const auto& word : words) {
            TrieNode* node = root;
            for (char ch : word) {
                int index = ch - 'a';
                if (!node->children[index]) {
                    node->children[index] = new TrieNode();
                }
                node = node->children[index];
                node->count++;  // Increment the count for each node
            }
        }
        
        // Calculate the prefix scores
        vector<int> result;
        for (const auto& word : words) {
            TrieNode* node = root;
            int score = 0;
            for (char ch : word) {
                int index = ch - 'a';
                node = node->children[index];
                score += node->count;  // Add the count at this prefix
            }
            result.push_back(score);
        }
        
        return result;
    }
};
