class Solution {
public:
    void backtracking(string current , int open , int close, vector<string> &ans , int index ,int n){
        if(index == n * 2){
            ans.push_back(current);
            return;
        }

        if(open < n)
        backtracking(current + '(' , open+1 , close , ans , index + 1 , n);
        if(close < open)
        backtracking(current + ')' , open , close + 1 , ans , index + 1 , n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtracking("" , 0, 0 , ans , 0 , n);
        return ans;
    }
};
