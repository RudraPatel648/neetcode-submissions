class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int> , vector<string>> mpp;

        for(int  i = 0; i < strs.size() ; i++)
        {
            vector<int> vec(26,0);
            for(int j = 0 ; j < strs[i].size() ; j++){
                vec[strs[i][j] - 'a']++;
            }
            mpp[vec].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for(auto it : mpp){
            ans.push_back(it.second);
        }

        return ans;
    }
};
