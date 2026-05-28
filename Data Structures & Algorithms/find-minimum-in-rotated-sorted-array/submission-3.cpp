class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int low = 0;
        int high = nums.size() - 1;
        int ans = nums[0];
        while(low <= high)
        {
            if(nums[low] < nums[high])
            {
                ans = min(ans , nums[low]);
                break;
            }

            int mid = low + ( high - low ) /2;
            ans = min(ans , nums[mid]);

            if(nums[mid] >= nums[low]) low = mid + 1;
            else high = mid - 1;
        }
        return ans;
    }
};
 