class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> mpp;
        for(int it : nums)
        mpp[it]++;

        vector<vector<int>> vec(nums.size() + 1); //+1 becuse , there isnt elemenet that appear 0 times
        for(auto it : mpp)
        vec[it.second].push_back(it.first);

        vector<int> res;
        for(int i = vec.size() - 1 ; i >= 0 ; i--)
        {
            for(auto ti : vec[i])
            {
            res.push_back(ti);
            if(res.size() == k) return res;
            }
        }
    }
};
