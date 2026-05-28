class Solution {
public:
    vector<int> stringToVec(string str)
    {
        vector<int> hash(26 , 0);
        for(char ch : str)
        hash[ch - 'a']++;
        return hash;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int> , vector<string>> mpp;

        for(string it : strs)
        {
            vector<int> hash = stringToVec(it);
            mpp[hash].push_back(it);
        }

        vector<vector<string>> ans;
        for(auto it : mpp)
        ans.push_back(it.second);

        return ans;
    }
};
