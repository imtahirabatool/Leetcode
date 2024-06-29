class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<set<int>> map(n);
        vector<vector<int>> res(n);
        vector<bool> visited(n);

        function<void(int, int)> dfs = [&](int v, int p) {
            visited[v] = true;
            if (v != p) res[v].push_back(p);
            for (int x : map[v]) {
                if (!visited[x]) dfs(x, p);
            }
        };

        for (const auto& edge : edges) {
            map[edge[0]].insert(edge[1]);
        }

        for (int i = 0; i < n; ++i) {
            fill(visited.begin(), visited.end(), false);
            dfs(i, i);
        }

        return res;
    }
};