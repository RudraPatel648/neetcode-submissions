class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        int time = 0;
        queue<pair<int, int>> q;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) fresh++;
                if (grid[i][j] == 2) q.push({i, j});
            }
        }

        while (fresh > 0 && !q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                auto current = q.front();
                q.pop();
                int row = current.first;
                int col = current.second;

                int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                for (int j = 0; j < 4; j++) {
                    int r = row + dir[j][0];
                    int c = col + dir[j][1];

                    if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && grid[r][c] == 1) {
                        grid[r][c] = 2;
                        q.push({r, c});
                        fresh--;
                    }
                }
            }
            time++;
        }
        return fresh == 0 ? time : -1;
    }
};
