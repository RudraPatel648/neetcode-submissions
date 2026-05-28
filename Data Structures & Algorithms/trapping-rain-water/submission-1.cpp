class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> vec(n , 0);
        int maximum = 0;
        for(int i = 1 ; i < n ; i++)
        {
            maximum = max(maximum , height[i-1]);
            vec[i] = maximum;
        }
        maximum = 0;
        for(int i = n - 1 ; i >= 0 ; i--)
        {
            if(i != n-1)
            maximum = max(maximum ,height[i + 1]);
            int current = min(maximum , vec[i]) - height[i];
            if(current > 0) vec[i] = current;
            else vec[i] = 0;
        }

        int res = accumulate(vec.begin() , vec.end() , 0);
        return res;
    }
};
