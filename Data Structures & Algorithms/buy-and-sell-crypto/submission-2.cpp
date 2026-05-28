class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int mini = INT_MAX;
        for(auto it : prices){
            mini = min(it , mini);
            ans = max(ans , it - mini) ;
        }
        return ans;
    }
};
