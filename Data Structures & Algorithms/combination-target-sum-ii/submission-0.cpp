class Solution {
   public:
    void backtrack(vector<int>& nums, vector<int>& current, vector<vector<int>>& ans, int index,
                   int sum, int target) {
        if (sum == target) {
            ans.push_back(current);
            return;
        }
        if (sum > target || index == nums.size()) return;
        current.push_back(nums[index]);
        backtrack(nums, current, ans, index + 1, sum + nums[index], target);
        current.pop_back();
        index++;
        while(index > 0 && index < nums.size() && nums[index] == nums[index-1]) index++;
        backtrack(nums, current, ans, index, sum, target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, current, ans, 0, 0, target);
        return ans;
    }
};
