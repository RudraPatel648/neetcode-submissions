class Solution {
   public:
    int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size();
        int COLS = heights[0].size();
        vector<vector<bool>> pac(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atl(ROWS, vector<bool>(COLS, false));

        for (int c = 0; c < COLS; c++) {
            dfs(0, c, pac, heights);
            dfs(ROWS - 1, c, atl, heights);
        }

        for (int r = 0; r < ROWS; r++) {
            dfs(r, 0, pac, heights);
            dfs(r, COLS - 1, atl, heights);
        }
        vector<vector<int>> ans;

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (pac[r][c] && atl[r][c]) {
                    ans.push_back({r, c});
                }
            }
        }
        return ans;
    }

    void dfs(int r, int c, vector<vector<bool>>& visited, vector<vector<int>>& heights) {
        visited[r][c] = true;
        for (auto [dr , dc] : directions) {
            int row = r + dr;
            int col = c + dc;

            if (row >= 0 && row < heights.size() && col >= 0 && col < heights[0].size() &&
                !visited[row][col] && heights[r][c] <= heights[row][col]) {
                dfs(row, col, visited, heights);
            }
        }
    }
};
