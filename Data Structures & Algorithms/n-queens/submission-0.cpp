class Solution {
public:
    unordered_set<int> col;
    unordered_set<int> posDiag;
    unordered_set<int> negDiag;

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n , string(n , '.'));
        dfs(0 , board , res);
        return res;
    }

    void dfs(int r , vector<string> &board , vector<vector<string>> &res){
        if(r == board.size()){
            res.push_back(board);
        }

        for(int c = 0 ; c < board.size() ; c++){
            
            if(col.count(c) || posDiag.count(r + c) || negDiag.count(r - c))
                continue;
            
            board[r][c] = 'Q';
            col.insert(c);
            posDiag.insert(r + c);
            negDiag.insert(r - c);

            dfs(r + 1 , board , res);

            board[r][c] = '.';
            col.erase(c);
            posDiag.erase(r + c);
            negDiag.erase(r - c);
        }
    }
};
