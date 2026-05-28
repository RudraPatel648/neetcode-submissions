class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size());
        prefix[0] = 1;
        vector<int> suffix(nums.size());
        suffix[nums.size() - 1] = 1;
        int prod;
        
        prod = 1;
        for(int i = 1 ; i < nums.size() ; i++)
        {
            prod *= nums[i - 1];
            prefix[i] = prod;
        }

        prod = 1;
        for(int i = nums.size() - 2 ; i >= 0 ; i--)
        {
            prod *= nums[i + 1];
            suffix[i] = prod;
        }

        vector<int> ans(nums.size());
        for(int i = 0 ; i < nums.size() ; i++)
        {
            ans[i] = prefix[i] * suffix[i];
        }

        return ans;
    }
};
