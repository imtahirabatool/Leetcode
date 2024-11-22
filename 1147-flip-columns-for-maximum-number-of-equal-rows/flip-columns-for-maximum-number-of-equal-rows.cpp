class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> patternCount;

        for (const auto& row : matrix) {
            string pattern = "";

            for (int j = 0; j < row.size(); ++j) {
                pattern += (row[j] ^ row[0]) ? '1' : '0';
            }
            patternCount[pattern]++;
        }

        int maxRows = 0;
        for (const auto& entry : patternCount) {
            maxRows = max(maxRows, entry.second);
        }
        return maxRows;
    }
};