class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = 0;
        int n = heights.size();
        int low = 0;
        int high = n - 1;

        while(low < high){
            int current = (high - low ) * min(heights[low], heights[high]);
            res = max(res , current);

            if(heights[low] < heights[high]) low++;
            else high--;
        }
        return res;
    }
};
