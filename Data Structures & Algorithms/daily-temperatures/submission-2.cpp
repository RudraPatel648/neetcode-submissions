class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> &temp = temperatures;
        if(!temp.size()) return {};
        vector<int> ans(temp.size() , 0);
        stack<pair<int,int>> st;
        for(int i = 0 ; i < temp.size() ; i++)
        {
            while(!st.empty() && st.top().first < temp[i]){
                ans[st.top().second] = i - st.top().second;
                st.pop();
            }
            st.push({temp[i] , i});
        }        
        return ans;
    }
};
