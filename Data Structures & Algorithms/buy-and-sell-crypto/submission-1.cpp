class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(auto it : prices){
            if(it < mini){
                if(mini != INT_MAX && maxi != INT_MIN)ans = max(maxi - mini , ans);
                mini = it;
                maxi = it;
                continue;
            }
            maxi = max(it , maxi);
        }
        ans = max( ans , maxi - mini);
        return ans;
    }
};
