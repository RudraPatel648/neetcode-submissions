class Solution {
   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxArea = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (grid[r][c] == 1) {
                    int currentArea = 1;
                    dfs(r, c, grid, currentArea);
                    maxArea = max(maxArea, currentArea);
                }
            }
        }

        return maxArea;
    }

    void dfs(int r, int c, auto& grid, int& area) {
        grid[r][c] = 0;

        int dir[4][2] = {
            {1 , 0},
            {0 , 1},
            {-1 , 0},
            {0 , -1}
        };

        for(int i = 0 ; i < 4 ; i++){
            int row = r + dir[i][0];
            int col= c + dir[i][1];

            if(
                row < 0 || row >= grid.size() ||
                col < 0 || col >= grid[0].size() ||
                grid[row][col] == 0
            )
            continue;

            area++;
            dfs(row , col , grid , area);
        }
    }
};
