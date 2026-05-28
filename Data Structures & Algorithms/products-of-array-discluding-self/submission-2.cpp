class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prefix = 1;
        vector<int> ans(n);
        ans[0] = 1;

        for(int i = 1 ; i < n ; i++)
        {
            prefix *= nums[i - 1];
            ans[i] = prefix;
        }

        int suffix = 1;
        for(int i = nums.size() - 2 ;i >=0 ; i--)
        {
            suffix *= nums[i + 1];
            ans[i] *= suffix;
        }

        return ans;
    }
};
