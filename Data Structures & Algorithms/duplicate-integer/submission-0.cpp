class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int,int> mpp;
        
        for(auto it : nums)
        {
            if(mpp.find(it) != mpp.end()) return true;
            mpp[it]++;
        }
        return false;
    }
};