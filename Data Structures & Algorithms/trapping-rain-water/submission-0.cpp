class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int maximum;
        vector<int> left(n , 0);
        vector<int> right(n , 0);
        // vector<int> ans(n , 0);

        maximum = 0;
        left[0] = 0;
        for(int i = 1; i < n ; i++)
        {
            maximum = max(maximum , height[i-1]);
            left[i] = maximum;
        } 

        maximum = 0;
        right[n-1] = 0;
        for(int i = n-2 ; i >= 0 ; i--)
        {
            maximum = max(maximum , height[i + 1]);
            right[i] = maximum;
        }

        int store = 0;
        for(int i = 0; i < n ; i++)
        {
            int current = min(left[i] , right[i]) - height[i];
            if(current > 0)
            store += current;
        }

        return store;
    }
};
