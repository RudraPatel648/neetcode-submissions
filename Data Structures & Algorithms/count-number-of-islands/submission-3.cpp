class Solution {
public:
    void dfs(int i , int j , vector<vector<char>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        grid[i][j] = '0';
        int nei[4][2] = { {1 , 0} , {0 , 1} , {-1 , 0} , {0 , -1}};

        for(int it = 0 ; it < 4 ; it++)
        {
            int nr = i + nei[it][0];
            int nc = j + nei[it][1];

            if(nr < 0 || nr >= n || nc < 0 || nc >= m || grid[nr][nc] == '0')
            continue;

            dfs(nr, nc,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(grid[i][j] == '1')
                {
                    dfs(i,j,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};
