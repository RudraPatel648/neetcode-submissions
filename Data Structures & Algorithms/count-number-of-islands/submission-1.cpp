class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int r = 0 ; r < grid.size() ; r++){
            for(int c = 0 ; c < grid[0].size() ; c++){
                if(grid[r][c] == '1'){
                    dfs(r , c , grid);
                    count++;
                }
            }
        }
        return count;
    }

    void dfs(int r , int c , auto& grid){
        grid[r][c] = '0';

        int dir[4][2] = { 
            {1 , 0},
            {0 , 1},
            {-1 , 0},
            {0 , -1}
        };

        for(int i = 0 ; i < 4 ; i++){
            int row = r + dir[i][0];
            int col = c + dir[i][1];

            if(
                row < 0 || row >= grid.size() || 
                col < 0 || col >= grid[0].size() ||
                grid[row][col] == '0'
            )
            continue;

            dfs(row , col , grid);
        }
    }
};
