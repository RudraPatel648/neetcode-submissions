class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> &temp = temperatures;
        vector<int> ans(n,0);
        for(int i = 0; i < n ; i++)
        {
            for(int j = i + 1 ; j < n ; j++)
            {
                if(temp[j] > temp[i]) {
                    ans[i] = j - i ;
                    break;
                }
            }
        }
        return ans;
    }
};
