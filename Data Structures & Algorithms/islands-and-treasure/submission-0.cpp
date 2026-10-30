class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        queue<vector<int>> q;
        for(int i = 0;i<=m-1;i++){
            for(int j = 0;j<=n-1;j++){
                if(grid[i][j] == 0){
                    q.push({0,i,j});
                }
            }
        }
        while(!q.empty()){
            auto it = q.front();
            int dis = it[0];
            int x = it[1];
            int y = it[2];
            q.pop();
            for(auto k : dir){
                int dx = k[0];
                int dy = k[1];
                int nx = x + dx;
                int ny = y + dy;
                if(nx>=0 && nx < m && ny >=0 && ny < n && (grid[nx][ny] != -1 && grid[nx][ny] != 0)){
                    if(grid[nx][ny] > dis + 1){
                        grid[nx][ny] = dis +1;
                        q.push({dis+1, nx,ny});
                    }
                }
            }
        }
    }
};
