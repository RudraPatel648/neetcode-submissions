class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> &temp = temperatures;
        if(!temp.size()) return {};
        vector<int> ans(temp.size() , 0);
        stack<int> st;
        for(int i = 0 ; i < temp.size() ; i++)
        {
            while(!st.empty() && temp[st.top()] < temp[i]){
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }        
        return ans;
    }
};
