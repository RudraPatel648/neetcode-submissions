class Solution {
   public:
    int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int minutes = 0;
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (grid[r][c] == 2) q.push({r, c});
                if (grid[r][c] == 1) fresh++;

            }
        }

        while (fresh > 0 && !q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                auto current = q.front();
                q.pop();
                int r = current.first;
                int c = current.second;

                for(int j = 0 ; j < 4 ; j++)
                {
                    int row = r + dir[j][0];
                    int col = c + dir[j][1];

                    if(row < 0 || row >= n ||
                        col < 0 || col >= m ||
                        grid[row][col] != 1
                    )
                    continue;

                    grid[row][col] = 2;
                    q.push({row , col});
                    fresh--;
                }
            }
            minutes++;
        }

        return (fresh == 0) ? minutes : -1;
    }
};
