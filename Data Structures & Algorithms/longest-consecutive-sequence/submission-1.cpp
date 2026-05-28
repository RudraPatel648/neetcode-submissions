class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> mpp;
        for(int it : nums)
        mpp[it]++;

        int count = 0;
        for(int it : nums)
        {
            if(mpp[it - 1] == 0)
            {
                int ccount = 0;
                while(mpp[it])
                {ccount++;
                it++;}
                count = max(count , ccount);
            }
        }
        return count;
    }
};
