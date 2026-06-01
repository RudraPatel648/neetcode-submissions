class Solution {
   public:
    int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int bfs(int r, int c, auto& grid) {
        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = 0;
        int cells = 1;
        while (!q.empty()) {
            auto current = q.front(); q.pop();
            int row = current.first;
            int col = current.second;

            for (int i = 0; i < 4; i++) {
                int nr = row + directions[i][0];
                int nc = col + directions[i][1];

                if(nr >= 0 && nr < grid.size() &&
                    nc >= 0 && nc < grid[0].size() &&
                    grid[nr][nc] == 1
                ){
                    q.push({nr,nc});
                    grid[nr][nc] = 0;
                    cells++;
                }
            }
        }
        return cells;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;
        for(int r = 0 ; r < row ; r++){
            for(int c = 0 ; c < col ; c++){
                if(grid[r][c] == 1){
                    ans = max(ans , bfs(r,c,grid));
                }
            }
        }
        return ans;
    }
};
