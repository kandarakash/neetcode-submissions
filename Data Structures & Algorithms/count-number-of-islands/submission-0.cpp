class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        for(int i = 0;i<=n-1;i++){
            for(int j = 0;j<=m-1;j++){
                if(grid[i][j] == '1'){
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    grid[i][j] = '0';
                    while(!q.empty()){
                        auto[x,y] = q.front();
                        q.pop();
                        for(auto it : dir){
                            int dx = it[0];
                            int dy = it[1];
                            int nx = x+dx;
                            int ny = y + dy;
                            if(nx>=0 && nx <n && ny >=0 && ny <m && grid[nx][ny] == '1'){   
                                grid[nx][ny] = '0';
                                q.push({nx,ny});
                            }
                        }
                    }
                    count++;
                }
            }
        }
        return count;
    }
};
