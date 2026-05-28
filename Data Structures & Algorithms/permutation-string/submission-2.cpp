class Solution {    

public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<int> hash1(26, 0);
        vector<int> hash2(26, 0);

        for(char c : s1){
            hash1[c - 'a']++;
        }

        int l =
         0;
        for(int r = 0 ; r < s2.size() ; r++){
            hash2[s2[r]-'a']++;


            while(r-l+1 > s1.size())
            {
                hash2[s2[l]-'a']--;
                l++;
            }
            if(r-l+1 == s1.size() && hash1 == hash2) return true;
        }

        return false;
    }
};
