class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it : times){
            int u = it[0];
            int v = it[1];
            int t = it[2];
            adj[u].push_back({v,t});
        }
        vector<int> dist(n+1,1e9);
        dist[k] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            auto [time,node] = pq.top();
            pq.pop();
            if(dist[node] < time) continue;
            for(auto it : adj[node]){
                int adjnode = it.first;
                int adjtime = it.second;
                if(time + adjtime < dist[adjnode]){
                    dist[adjnode] = time+adjtime;
                    pq.push({time+ adjtime, adjnode});
                }
            }
        }
        int maxi = *max_element(dist.begin()+1,dist.end());
        if(maxi == 1e9) return -1;
        return maxi;
    }
};
