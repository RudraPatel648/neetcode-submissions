class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int , int> um;

        for(int it : nums)
        {
            if(um[it] == 1) return true;
            else um[it] = 1;
        }

        return false;
    }
};