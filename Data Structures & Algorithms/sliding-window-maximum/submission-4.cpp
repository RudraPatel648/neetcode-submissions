class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int high = 0;
        int low = 0;
        int n = nums.size();
        deque<int> dq;
        vector<int> ans;
        while(high < n){
            while(!dq.empty() && nums[high] > dq.back()) dq.pop_back();
            dq.push_back(nums[high]);

            high++;
            if(high >= k){
                ans.push_back(dq.front());

                if(dq.front() == nums[low]) dq.pop_front();
                low++;
            } 
        }

        return ans;
    }
};
