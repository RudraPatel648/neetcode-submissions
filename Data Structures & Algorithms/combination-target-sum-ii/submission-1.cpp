class Solution {
   public:
    void backtrack(vector<int>& nums, vector<int>& current, vector<vector<int>>& ans, int index,
                   int sum, int target) {
        // ----------------Base Case----------------
        if (sum == target) {
            ans.push_back(current);
            return;
        }
        // -----------------------------------------

        for(int i = index ; i < nums.size() ; i++){
            //Handeling the skipping duplicate part
            if(i > index && nums[i] == nums[i - 1]) continue;
            //pruning
            if(sum + nums[i]> target) break;

            current.push_back(nums[i]);
            backtrack(nums , current , ans , i + 1,sum+nums[i], target);
            current.pop_back();
        }        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, current, ans, 0, 0, target);
        return ans;
    }
};
