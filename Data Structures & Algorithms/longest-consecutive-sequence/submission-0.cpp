class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxLength = 0;

        // Hash
        unordered_map<int , int> mpp;
        for(int it : nums)
        mpp[it]++;

        // Head finding
        vector<int> heads;
        for(int it : nums)
        {
            if(mpp[it-1] == 0)
            heads.push_back(it);
        }

        // Length Checking
        for(int i = 0 ; i < heads.size() ; i++)
        {
            int len = 0;
            while(mpp[heads[i]] != 0)
            {
                len++;
                heads[i]++;
            }
            maxLength = max(maxLength , len);
        }

        return maxLength;
    }
};
