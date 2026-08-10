class Solution {
public:
    int dfs(int i , int j , vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        grid[i][j] = 0;
        int current = 1;
        int nei[4][2] = {{1,0} , {0,1} , {-1,0} , {0,-1}};
        for(int it = 0 ; it < 4 ; it++)
        {
            int nr = i + nei[it][0];
            int nc = j + nei[it][1];

            if(nr < 0 || nr >= n || nc < 0 || nc >= m || grid[nr][nc] == 0) continue;
            current += dfs(nr , nc , grid);
        } 

        return current;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(grid[i][j] == 1)
                    ans = max(ans,dfs(i, j , grid));
            }
        }
        return ans;
    }
};
