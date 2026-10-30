
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    queue<pair<int,int>> q;
                    q.push({i, j});
                    grid[i][j] = 0;

                    int area = 0;

                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        area++;

                        for (auto it : dir) {
                            int nx = x + it[0];
                            int ny = y + it[1];

                            if (nx >= 0 && nx < n &&
                                ny >= 0 && ny < m &&
                                grid[nx][ny] == 1) {
                                grid[nx][ny] = 0;
                                q.push({nx, ny});
                            }
                        }
                    }

                    maxi = max(maxi, area);
                }
            }
        }

        return maxi;
    }
};
