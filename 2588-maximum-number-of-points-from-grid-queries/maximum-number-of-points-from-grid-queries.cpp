class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans(queries.size());
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<pair<int, int>> sortedQ;

        for (int i = 0; i < queries.size(); i++)
            sortedQ.push_back({queries[i], i});

        sort(sortedQ.begin(), sortedQ.end());

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;
        pq.push({grid[0][0], 0, 0});
        vis[0][0] = true;

        int points = 0;
        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        for (auto& q : sortedQ) {
            int qVal = q.first, qIdx = q.second;
            while (!pq.empty() && pq.top()[0] < qVal) {
                auto curr = pq.top();
                pq.pop();
                int r = curr[1], c = curr[2];
                points++;
                for (auto d : dirs) {
                    int x = r + d.first, y = c + d.second;
                    if (x >= 0 && y >= 0 && x < m && y < n && !vis[x][y]) {
                        pq.push({grid[x][y], x, y});
                        vis[x][y] = true;
                    }
                }
            }
            ans[qIdx] = points;
        }
        return ans;
    }
};