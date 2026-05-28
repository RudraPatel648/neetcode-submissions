class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int high = 0;
        int low = 0;
        int n = nums.size();
        deque<int> dq;
        vector<int> ans;
        while(high < n){
            while(!dq.empty() && nums[high] > nums[dq.back()]) dq.pop_back();
            dq.push_back(high);

            high++;
            if(high >= k){
                ans.push_back(nums[dq.front()]);

                if(dq.front() == low) dq.pop_front();
                low++;
            } 
        }

        return ans;
    }
};
