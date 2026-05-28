class Solution {
public:
    void backtracking(vector<int>&nums,vector<int>& current , vector<vector<int>>& ans, unordered_set<int> &hash){
        if(current.size() == nums.size()) {
            ans.push_back(current);
            return;   
        }

        for(int i = 0 ; i < nums.size() ; i++){
            if(!hash.count(nums[i])){
                hash.insert(nums[i]);
                current.push_back(nums[i]);

                backtracking(nums , current , ans ,hash);
                current.pop_back();
                hash.erase(nums[i]);
            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        unordered_set<int> hash;
        backtracking(nums , current , ans, hash);
        return ans;
    }
};
