class dsu{
private:
    vector<int> parent;
    vector<int> rank;
public:
    bool check = false;
    dsu(int n){
        parent.resize(n+1);
        rank.assign(n+1,1);
        for(int i = 0;i<=n;i++){
            parent[i] = i;
        }
    }
    int par(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = par(parent[node]);
    }
    void ur(int u, int v){
        int pu = par(u);
        int pv = par(v);
        if(pu == pv){
            check = true;
            return;
        }
        if(rank[pu] > rank[pv]){
            parent[pv] = pu;
        }
        else if(rank[pu]<rank[pv]){
            parent[pu] = pv;
        }
        else{
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        dsu ds(n);
        for(int i = 0;i<=n-1;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            ds.ur(u,v);
            if(ds.check == true){
                return {u,v};
            }
        }
        return {};
    }
};
