class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& adj, vector<bool>& vis, int src, int dest) {
        vis[src] = true;

        if (src == dest) {
            return true;
        }

        bool isReachable = false;
        for (auto& adjNode : adj[src]) {
            if (!vis[adjNode]) {
                isReachable = isReachable || dfs(adj, vis, adjNode, dest);
            }
        }
        return isReachable;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;

        for (auto& edges : prerequisites) {
            int u = edges[0];
            int v = edges[1];
            adj[u].push_back(v);
        }

        int qs = queries.size();
        vector<bool> result(qs);

        for (int i = 0; i < qs; i++) {
            int u = queries[i][0];
            int v = queries[i][1];
            vector<bool> vis(numCourses, false);
            result[i] = dfs(adj, vis, u, v);
        }
        return result;
    }
};