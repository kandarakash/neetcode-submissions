class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>& adj,
             vector<int>& vis) {
        vis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                if(!dfs(it, node, adj, vis))
                    return false;
            }
            else if(it != parent) {
                return false;
            }
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n, 0);
        if(!dfs(0, -1, adj, vis))
            return false;
        for(int i = 0; i < n; i++) {
            if(!vis[i])
                return false;
        }
        return true;
    }
};