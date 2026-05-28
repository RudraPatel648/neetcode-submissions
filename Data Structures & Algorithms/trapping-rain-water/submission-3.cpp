class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMost = height[0];
        int rightMost = height[n-1];
        int left = 0;
        int right = n - 1;
        int res = 0;

        while(left < right)
        {
            if(leftMost <= rightMost){
                left++;
                leftMost = max(leftMost , height[left]);
                res += leftMost - height[left];
            }
            else{
                right--;
                rightMost = max(rightMost , height[right]);
                res += rightMost - height[right];
            }
        }

        return res;
    }
};
