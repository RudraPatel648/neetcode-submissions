class Solution {
public:
    void backtrack(vector<int> &nums , vector<int> &current , vector<vector<int>> &ans , int index , int sum , int target){
        if(index == nums.size() || sum >= target){
            if(sum==target){
                ans.push_back(current);
            }
            return;
        }

        current.push_back(nums[index]);
        backtrack(nums , current , ans , index , sum + nums[index] , target);
        current.pop_back();
        backtrack(nums , current , ans , index+1, sum , target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> current;
        backtrack(nums , current , ans , 0 , 0 , target);
        return ans;
    }
};
