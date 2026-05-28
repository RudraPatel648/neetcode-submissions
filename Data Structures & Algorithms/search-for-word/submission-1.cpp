class Solution {
public:
    bool backtrack(vector<vector<char>>&board , string word  , int index ,int row , int col){
        int n = board.size();
        int m = board[0].size();
        //Pruning Condition ---
        if(index == word.size()) return true;
        if(row > n-1 || row < 0 || col > m-1 || col < 0){
            return false;
        }
        if(board[row][col] != word[index]) return false;

        index++;

        char temp = board[row][col];
        board[row][col] = '#';

        bool found = (backtrack(board , word , index , row - 1 , col )
        || backtrack(board , word , index , row, col + 1 )
        || backtrack(board , word , index , row + 1, col )
        || backtrack(board , word , index , row, col - 1));

        board[row][col] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(board[i][j] == word[0]){
                    if(backtrack(board , word , 0 , i , j)) return true;
                }
            }
        }

        return false;
    }
};
