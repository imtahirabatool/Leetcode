class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        map<int, vector<int>> adj;
        int m = isConnected.size(), n = isConnected[0].size();

        // Convert the isConnected matrix into an adjacency list adj 
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    adj[i + 1].push_back(j + 1);
                }
            }
        }
        int count = 0;
        queue<int> q;
        vector<int> vis(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                q.push(i);
                count++;
            }
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                for (auto x : adj[curr]) {
                    if (!vis[x]) {
                        vis[x] = 1;
                        q.push(x);
                    }
                }
            }
        }
        return count;
    }
};