class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, const string& word, int i, int j,
             int count) {
        if (count == word.size()) {
            return true;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
            board[i][j] != word[count]) {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = ' '; // Mark this cell as visited

        bool found = dfs(board, word, i + 1, j, count + 1) ||
                     dfs(board, word, i - 1, j, count + 1) ||
                     dfs(board, word, i, j + 1, count + 1) ||
                     dfs(board, word, i, j - 1, count + 1);

        board[i][j] = temp; // Restore the cell

        return found;
    }
};