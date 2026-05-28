class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int index = 0;
        int n = nums.size();
        vector<vector<int>> ans;
        for(int index = 0 ; index < n - 2 ; index++){
            if(nums[index] > 0) break;
            if(index > 0 && nums[index] == nums[index-1]) continue;
            
            int p1 = index + 1;
            int p2 = n - 1;

            while(p1 < p2){
                if(nums[index] + nums[p1] + nums[p2] == 0){
                    ans.push_back({nums[index] , nums[p1] , nums[p2]});
                    p1++;
                    p2--;
                    while(p1 < p2 && nums[p1] == nums[p1-1]) p1++;
                    while(p1 < p2 && nums[p2] == nums[p2+1]) p2--;
                }
                else if(nums[index] + nums[p1] + nums[p2] > 0) p2--;
                else p1++;
            }
        }
        return ans;
    }
};
