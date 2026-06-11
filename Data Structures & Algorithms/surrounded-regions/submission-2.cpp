class Solution {
   public:
    set<pair<int, int>> hash;
    void solve(vector<vector<char>>& board) {
        int ROWS = board.size();
        int COLS = board[0].size();
        for (int r = 0; r < ROWS; r++) {
            if(board[r][0] == 'O')
            dfs(r, 0, board);
            if(board[r][COLS-1] == 'O')
            dfs(r, COLS - 1, board);
        }

        for (int c = 0; c < COLS; c++) {
            if(board[0][c] == 'O')
            dfs(0, c, board);
            if(board[ROWS-1][c] == 'O')
            dfs(ROWS - 1, c, board);
        }

        for(int r = 0 ; r < ROWS ; r++){
            for(int c = 0 ; c < COLS ; c++)
            {
                if(!hash.count({r,c}))
                board[r][c] = 'X';
            }
        }
    }

    void dfs(int r, int c, vector<vector<char>>& board) {
        if (hash.count({r, c})) return;
        hash.insert({r, c});

        int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        for (int i = 0; i < 4; i++) {
            int row = r + dir[i][0];
            int col = c + dir[i][1];

            if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() ||
                board[row][col] != 'O' )
                continue;

            dfs(row, col, board);
        }
    }
};
