class Solution {
public:
    void dfs(int node, vector<vector<int>>&adj, vector<int>&vis){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i = 0;i<=edges.size()-1;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[v].push_back(u);
            adj[u].push_back(v);
        }
        vector<int>vis(n,0);
        int compo = 0;
        for(int i = 0;i<=n-1;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                compo++;
            }
        }
        return compo;
    }
};
