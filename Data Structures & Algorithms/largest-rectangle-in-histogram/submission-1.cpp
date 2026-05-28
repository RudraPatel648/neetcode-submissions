class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int>&h = heights;
        int n = h.size();
        stack<int> st;
        vector<int> leftMost(n , -1);
        vector<int> rightMost(n , n);

        for(int i = 0 ; i < h.size() ; i++){
            while(!st.empty() && h[i] < h[st.top()])
            {
                rightMost[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();

        for(int i = h.size() - 1; i >= 0 ; i--){
            while(!st.empty() && h[i] < h[st.top()]){
                leftMost[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        int res = 0;
        for(int i =  0 ; i < h.size() ; i++){
            int current = (rightMost[i] - leftMost[i] - 1) * h[i];
            res = max(current , res);
        }
        return res;
    }
};
