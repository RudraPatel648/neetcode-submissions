class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        int zeroProd = 1;
        int zeroCount = 0;

        for(int it : nums)
        {   
            if(zeroCount == 1 && it == 0)
            {
                prod = 0;
                zeroProd = 0;
                break;
            }

            if(it == 0)
            {
                prod = 0;   
                zeroCount++;
            }            
            else{
                prod *= it;
                zeroProd *= it;
            }
        }

        vector<int> ans(nums.size() , 1);

        if(zeroCount > 1)
        {
            vector<int> vec(nums.size() , 0);
            return vec;
        }
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i] == 0)
            ans[i] = zeroProd;
            else
            ans[i] = prod / nums[i];
        }
        return ans;
    }
};
 