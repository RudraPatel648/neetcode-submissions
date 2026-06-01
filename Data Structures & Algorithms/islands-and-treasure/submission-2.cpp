class Solution {
   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }

        int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int r = row + directions[i][0];
                int c = col + directions[i][1];

                if(r < 0 || r >= grid.size()||
                    c < 0 || c >= grid[0].size() || grid[r][c] != INT_MAX
                ){
                    continue;
                }

                grid[r][c] = grid[row][col] + 1;
                q.push({r,c});
            }
        }
    }
};
