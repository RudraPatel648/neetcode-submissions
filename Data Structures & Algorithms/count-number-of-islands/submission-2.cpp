class Solution {
   public:
    void dfs(int r, int c, vector<vector<char>>& grid, set<pair<int, int>>& hash) {
        int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        hash.insert({r, c});

        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];

            if (nr < 0 || nr >= grid.size() || nc < 0 || nc >= grid[0].size() ||
                hash.count({nr, nc}) || grid[nr][nc] == '0')
                continue;
            dfs(nr, nc, grid, hash);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        set<pair<int, int>> hash;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !hash.count({i, j})) {
                    dfs(i, j, grid, hash);
                    ans++;
                }
            }
        }
        return ans;
    }
};
