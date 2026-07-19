class Solution {
public:
    int dir[4][2] = {{1,0} , {0,1} , {-1,0} , {0,-1}};
    void dfs(int r , int c , vector<vector<int>>& grid , int &current)
    {
        grid[r][c] = 0;
        current++;
        for(int i = 0; i < 4 ; i++)
        {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];

            if(nr < 0 || nc < 0 || nr >= grid.size() || nc >= grid[0].size() || grid[nr][nc] == 0)
            continue;
            dfs(nr , nc , grid , current);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxArea = 0;
        for(int i = 0; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(grid[i][j] == 1)
                {
                    int current = 0;
                    dfs(i , j , grid , current);
                    maxArea = max(maxArea , current);
                }
            }
        }
        return maxArea;
    }
};
