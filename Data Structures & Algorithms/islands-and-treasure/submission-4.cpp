class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int INF = 2147483647; 
        int n = grid.size() ; int m = grid[0].size();
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(!grid[i][j])
                    q.push({i,j});
            }
        }

        while(!q.empty())
        {
            auto [row , col] = q.front();
            q.pop();

            int dir[4][2] = {{1,0} , {0,1} , {-1 , 0} , {0,-1}};
            for(int i = 0 ; i < 4; i++)
            {
                int nr = row + dir[i][0];
                int nc = col + dir[i][1];

                if(nr < 0 || nr >= n || nc < 0 || nc >= m || grid[nr][nc] != INF) continue;
                grid[nr][nc] = grid[row][col] + 1;
                q.push({nr , nc});
            }
        }
    }
};
