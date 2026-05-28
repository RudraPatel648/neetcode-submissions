class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> &A = (nums1.size() < nums2.size()) ? nums1 : nums2;
        vector<int> &B = (nums1.size() < nums2.size()) ? nums2 : nums1;

        int total = A.size() + B.size();
        int half = (total) / 2;

        if(B.size() < A.size()) swap(A,B);

        int low = -1;
        int high = A.size() - 1;

        while(low <= high){
            int i = low + (high - low) / 2;
            int j = half - i - 2;

            int ALeft = (i >= 0) ? A[i] : INT_MIN;
            int ARight = (i + 1 < A.size()) ? A[i + 1] : INT_MAX;

            int BLeft = (j >= 0) ? B[j] : INT_MIN;
            int BRight = (j + 1 < B.size()) ? B[j + 1] : INT_MAX;

            if(ALeft <= BRight && BLeft <= ARight)
            {
                if(total % 2 == 0){
                    return (double)(max(ALeft , BLeft) + min(ARight , BRight)) / 2.0;
                }
                return (double)min(ARight , BRight);
            }

            if(ALeft > BRight)
                high = i - 1;
            else 
                low = i + 1;
        }

        return -1;
    }
};
