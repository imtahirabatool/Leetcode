class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ball_colors;
        unordered_map<int, int> color_count;
        vector<int> result;
        int distinctColors = 0;

        for (auto& query : queries) {
            int ball = query[0], color = query[1];

            if (ball_colors.find(ball) != ball_colors.end()) {
                int old_color = ball_colors[ball];
                color_count[old_color]--;

                if (color_count[old_color] == 0) {
                    distinctColors--;
                }
            }
            ball_colors[ball] = color;
            color_count[color]++;

            if (color_count[color] == 1) {
                distinctColors++;
            }
            result.push_back(distinctColors);
        }
        return result;
    }
};