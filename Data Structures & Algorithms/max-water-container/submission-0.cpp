class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        int low = 0;
        int high = n- 1;
        int maxi = INT_MIN;
        while(low< high)
        {
            int current = (high - low) * (min(heights[low] , heights[high]));
            maxi = max(maxi , current);

            if(heights[low] < heights[high]) low++;
            else high--;
        }

        return maxi;
    }
};
