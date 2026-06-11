class Solution {
   public:
    int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 1) {
                    res = max(res, bfs(r, c, grid));
                }
            }
        }
        return res;
    }

    int bfs(int r, int c, vector<vector<int>>& grid) {
        grid[r][c] = 0;
        int area = 1;
        queue<pair<int, int>> q;
        q.push({r, c});

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int it = 0; it < 4; it++) {
                int nr = row + dir[it][0];
                int nc = col + dir[it][1];

                if (nr < 0 || nr >= grid.size() || nc < 0 || nc >= grid[0].size() ||
                    grid[nr][nc] == 0)
                    continue;
                grid[nr][nc] = 0;
                area++;
                q.push({nr, nc});
            }
        }
        return area;
    }
};
