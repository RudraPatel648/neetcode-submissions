class Solution {
   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 0) q.push({r, c});
            }
        }

        int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto current = q.front();
                q.pop();
                int r = current.first;
                int c = current.second;

                for(int j = 0 ; j < 4 ; j++){
                    int row = r + dir[j][0];
                    int col = c + dir[j][1];

                    if(
                        row < 0 || row >= grid.size() ||
                        col < 0 || col >= grid[0].size() ||
                        grid[row][col] != INT_MAX
                    )
                    continue;

                    grid[row][col] = grid[r][c] + 1;
                    q.push({row , col});
                }
            }
        }
    }
};
