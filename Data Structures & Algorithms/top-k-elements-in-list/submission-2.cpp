class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mpp;
        for(int it : nums)
        mpp[it]++;

        vector<pair<int,int>> vec;
        for(auto it : mpp)
            vec.push_back({it.first , it.second});

         sort(vec.begin(), vec.end(),
        [](pair<int,int> a, pair<int,int> b) {
            return a.second < b.second;
        });

        vector<int>ans;
        int count = 0;
        for(int i = vec.size() - 1 ;i >= 0 && count < k; i--)
        {ans.push_back(vec[i].first);
        count++;}
        
        return ans;
    }
};
