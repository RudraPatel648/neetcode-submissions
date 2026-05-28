class Solution {
public:
    void backtracking(vector<int> &nums , vector<int> &current , vector<vector<int>>& ans , int index){
        if(index == nums.size()){
            ans.push_back(current);
            return;
        }

        current.push_back(nums[index]);
        backtracking(nums , current , ans , index + 1);
        current.pop_back();
        index++;
        while(index > 0 && index < nums.size() && nums[index] == nums[index - 1]) index++;
        backtracking(nums , current , ans , index);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        sort(nums.begin() , nums.end());
        backtracking(nums , current , ans , 0);
        return ans;
    }
};
