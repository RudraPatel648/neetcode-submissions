class Solution {
public:
    void solve(vector<vector<char>>& board) {
        set<pair<int,int>> visited;
        int ROWS = board.size();
        int COLS = board[0].size();

        for(int c = 0 ; c < COLS ; c++){
            dfs(0 , c , visited , board);
            dfs(ROWS-1 , c , visited , board);
        }

        for(int r = 0 ; r < ROWS ; r++){
            dfs(r , 0 , visited , board);
            dfs(r , COLS - 1, visited , board);
        }

        for(int r = 0 ; r < ROWS ; r++){
            for(int c = 0 ; c < COLS ; c++){
                if(board[r][c] == 'O' && !visited.count({r , c})){
                    board[r][c] = 'X';
                }
            }
        }
    }

    void dfs(int r , int c , auto& visited , auto&board){
        if(board[r][c] == 'O') visited.insert({r , c});
        else return;

        int directions[4][2] = {{1,0} , {0,1} , {-1 , 0} , {0 , -1}};
        for(int i = 0 ; i < 4 ; i++){

            int row = r + directions[i][0];
            int col = c + directions[i][1];

            if(row >= 0 && row < board.size() &&
                col >= 0 && col < board[0].size() &&
                board[row][col] == 'O' &&
                !visited.count({row , col})
            ){
                dfs(row , col , visited , board);
                // visited.insert({row , col});
            }
        }
    }
};
