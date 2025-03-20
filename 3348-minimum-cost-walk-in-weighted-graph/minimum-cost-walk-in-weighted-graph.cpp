class Solution {
public:
    void bfs(int node, vector<int>& vis, vector<vector<pair<int, int>>>& adj,
             int& band, int& cnt) {
        queue<int> q;
        q.push(node);
        vis[node] = cnt;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto child : adj[u]) {
                int v = child.first;
                int w = child.second;
                band &= w;
                if (vis[v] == 0) {
                    vis[v] = cnt;
                    q.push(v);
                }
            }
        }
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& query) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto v : edges) {
            adj[v[0]].emplace_back(v[1], v[2]);
            adj[v[1]].emplace_back(v[0], v[2]);
        }
        vector<int> vis(n, 0);
        int cnt = 0;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                int band = 131071;
                cnt++;
                bfs(i, vis, adj, band, cnt);
                mp[cnt] = band;
            }
        }
        vector<int> ans;
        for (auto q : query) {
            int u = q[0];
            int v = q[1];
            if (vis[u] == vis[v]) {
                ans.push_back(mp[vis[u]]);
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};