class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> originalString = strs;
        for(int i = 0 ; i < strs.size() ; i++)
        {
            sort(strs[i].begin() , strs[i].end());
        }
        map<string , vector<string>> mpp;
        for(int i = 0 ; i < strs.size() ; i++)
        {
            mpp[strs[i]].push_back(originalString[i]);
        }
        vector<vector<string>> vec;
        for(auto it : mpp)
        {
            vec.push_back(it.second);
        }

        return vec;
    }
};
