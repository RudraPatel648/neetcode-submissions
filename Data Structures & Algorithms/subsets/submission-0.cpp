class Solution {
public:
    void backtrack(vector<int> &nums , vector<int> current , int index , vector<vector<int>> &ans){
        if(index == nums.size()){
            ans.push_back(current);
            return;
        }
        backtrack(nums , current , index + 1 , ans);
        current.push_back(nums[index]);
        backtrack(nums , current , index + 1 , ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        if(!nums.size()) return {};
        vector<vector<int>> ans;
        backtrack(nums , {} , 0 , ans);
        return ans;
    }
};
