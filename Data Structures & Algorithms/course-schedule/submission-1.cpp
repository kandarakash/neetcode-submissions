class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        if(edges.size() == 0) return true;
        vector<vector<int>> adj(n);
        for(int i = 0;i<=edges.size()-1;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[v].push_back(u);
        }
        vector<int> indegree(n);
        for(int i = 0;i<=n-1;i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i = 0 ;i<=n-1;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node]){
                indegree[it] = indegree[it]-1;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        if(ans.size() == n){
            return true;
        }
        else{
            return false;
        }
    }
};
