class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int n = nums1.size();
        int m = nums2.size();
        int total = n + m;

        int half = (total + 1) / 2;

        vector<int>& a = nums1;
        vector<int>& b = nums2;

        int low = 0;
        int high = n;

        while (low <= high) {
            int cut1 = low + (high - low) / 2;
            int cut2 = half - cut1;

            int leftA = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int rightA =(cut1 ==n) ? INT_MAX : nums1[cut1];

            int leftB = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int rightB = (cut2 ==m) ? INT_MAX : nums2[cut2];

            if(leftA <= rightB && leftB <= rightA) {
                if(total % 2){
                    return (double)max(leftA , leftB);
                }
                else{
                    return (max(leftA , leftB) + min(rightA , rightB)) / 2.0;
                }
            }
            else if(leftA > rightB ) high = cut1 - 1;
            else low = cut1 + 1;
        }

        return -1;
    }
};
