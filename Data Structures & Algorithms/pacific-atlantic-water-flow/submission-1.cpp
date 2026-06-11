class Solution {
   public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        map<pair<int, int>, int> pacific;
        map<pair<int, int>, int> atlantic;

        int ROWS = heights.size();
        int COLS = heights[0].size();
        for (int c = 0; c < COLS; c++) {
            dfs(0, c, heights, pacific);
            dfs(ROWS - 1, c, heights, atlantic);
        }

        for (int r = 0; r < ROWS; r++) {
            dfs(r, 0, heights, pacific);
            dfs(r, COLS - 1, heights, atlantic);
        }

        vector<vector<int>> ans;

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (pacific.count({r,c}) && atlantic.count({r, c})) ans.push_back({r, c});
            }
        }
        return ans;
    }

    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    void dfs(int r, int c, auto& heights, auto& mpp) {
        if (mpp.count({r, c})) return;
        mpp[{r, c}] = 1;

        for (int i = 0; i < 4; i++) {
            int row = r + dir[i][0];
            int col = c + dir[i][1];

            if (row < 0 || row >= heights.size() || col < 0 || col >= heights[0].size() ||
                heights[row][col] < heights[r][c])
                continue;

            dfs(row, col, heights, mpp);
        }
    }
};
