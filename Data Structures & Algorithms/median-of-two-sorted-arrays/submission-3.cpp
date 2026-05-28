class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> &a = nums1;
        vector<int> &b = nums2;
        if(b.size() < a.size()) return findMedianSortedArrays(b , a);

        int n = a.size() + b.size();
        int half = (n + 1) / 2;

        int low = 0;
        int high = a.size();
        while(low <= high){
            int cut1 = low + (high - low) / 2;
            int cut2 = half - cut1;

            int l1 = (cut1 == 0) ? INT_MIN : a[cut1-1];
            int r1 = (cut1 == a.size()) ? INT_MAX : a[cut1];

            int l2 = (cut2 == 0) ? INT_MIN : b[cut2-1];
            int r2 = (cut2 == b.size()) ? INT_MAX : b[cut2];

            if(l2 <= r1 && l1 <= r2)
                return (n % 2) ? max(l1,l2) : (max(l1,l2) + min(r1,r2)) / 2.0;

            else if(l1 > r2) high = cut1 - 1;
            else low = cut1 + 1;
        }
        return 0;
    }
};
