class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> vec;
        int p1  = 0;int p2 = 0;
        while(p1 < n && p2 < m)
        {
            if(nums1[p1] < nums2[p2]){
                vec.push_back(nums1[p1]);
                p1++;
            }
            else{
                vec.push_back(nums2[p2]);
                p2++;
            }
        }

        while(p1 < n)
        {
            vec.push_back(nums1[p1]);
            p1++;
        }
        while(p2 < m)
        {
            vec.push_back(nums2[p2]);
            p2++;
        }

        if(vec.size() % 2 == 0) {
            return (double)(vec[vec.size() / 2] + vec[(vec.size() / 2 ) - 1]) / 2;
        }
        else{
            return (double)vec[vec.size() / 2];
        }
    }
};