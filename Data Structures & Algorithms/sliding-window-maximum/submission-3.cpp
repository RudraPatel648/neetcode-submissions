class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        int l = 0;
        for(int r = 0 ; r < nums.size() ; r++){
            while(!dq.empty() && nums[dq.back()] < nums[r]){
                dq.pop_back();
            }
            dq.push_back(r);

            if(l > dq.front()){
                dq.pop_front();
            }

            if(r + 1 >= k){
                ans.push_back(nums[dq.front()]);
                l++;
            }
        }

        return ans;
    }
};
