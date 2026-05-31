class Solution {
   public:
    int directions[4][2] = {
        {1, 0}, {-1, 0},
        {0, 1}, {0, -1}
    };


    void dfs(auto& grid, int r, int c) {
        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = '0';

        while (!q.empty()) {
            auto current = q.front();
            q.pop();

            int row = current.first;
            int col = current.second;

            for (int i = 0; i < 4; i++) {
                int nr = row + directions[i][0];
                int nc = col + directions[i][1];

                if(nc >=0 && nc < grid[0].size() && nr >=0 && nr < grid.size()
                    && grid[nr][nc] == '1'){
                        q.push({nr , nc});
                        grid[nr][nc] = '0';
                    }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int ROW = grid.size();
        int COL = grid[0].size();

        int island = 0;

        for (int r = 0; r < ROW; r++) {
            for (int c = 0; c < COL; c++) {
                if (grid[r][c] == '1') {
                    dfs(grid, r, c);
                    island++;
                }
            }
        }
        return island;
    }
};
