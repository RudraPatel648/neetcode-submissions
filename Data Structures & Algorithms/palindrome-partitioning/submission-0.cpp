class Solution {
public:
    void dfs(int j , int i , vector<string> &part, string &s , vector<vector<string>> &res){
        if(i >= s.size()){
            if(i == j){
                res.push_back(part);
            }
            return;
        }

        string subS= s.substr(j , i - j + 1);
        string temp= subS;
        reverse(temp.begin() , temp.end());
        if(temp==subS){
            part.push_back(s.substr(j , i - j + 1));
            dfs(i+1 , i+1 , part , s , res);
            part.pop_back();
        }

        dfs(j , i+1 , part , s , res);        
    }

    vector<vector<string>> partition(string s) {
        vector<string> part;
        vector<vector<string>> res;
        dfs(0,0,part,s,res);
        return res;
    }

};
