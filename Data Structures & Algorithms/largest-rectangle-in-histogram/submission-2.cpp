class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        vector<int> &h = heights;
        int n = h.size();
        vector<int> leftSide(n , -1);
        vector<int> rightSide(n , n);

        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && h[i] < h[st.top()]){
                rightSide[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n - 1 ; i >= 0 ; i--){
            while(!st.empty() && h[i] < h[st.top()]){
                leftSide[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        int res = 0;
        for(int i = 0 ; i < n ; i++){
            int width = rightSide[i] - leftSide[i] - 1;
            int result = width * h[i];
            res = max(result , res);
        }
        return res;
    }
};
