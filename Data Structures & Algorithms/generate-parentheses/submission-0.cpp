class Solution {
public:
    void backtracking(string current , int openP, vector<string> &ans , int index , int n){
        if(index == n && !openP){
            ans.push_back(current);
            return;
        }
        if(n - index < openP) return;

        backtracking(current + '(' , openP+1 , ans , index + 1 , n);
        if(openP)
        backtracking(current + ')' , openP-1 , ans , index + 1 , n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtracking("" , 0 , ans , 0 , (n * 2));
        return ans;
    }
};
