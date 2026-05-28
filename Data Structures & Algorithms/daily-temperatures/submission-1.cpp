class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>& temp = temperatures;
        int n = temp.size();
        vector<int> ans(n , 0);
        stack<pair<int , int>> st;
        for(int i = 0 ; i < n ; i++){
            if(st.empty()){
                st.push({temp[i] , i});
                continue;
            }
            auto top = st.top();
            while(!st.empty() && temp[i] > top.first)
            {
                ans[top.second] = i - top.second;
                st.pop();
                top = st.top();
            }
            if(st.empty() || temp[i] <= top.first){
                st.push({temp[i] , i});
            }
        } 

        return ans;
    }
};
