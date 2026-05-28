class Solution {    

public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        unordered_map<char , int> hash1;
        unordered_map<char , int> hash2;

        for(char c : s1){
            hash1[c]++;
        }

        int l =
         0;
        for(int r = 0 ; r < s2.size() ; r++){
            hash2[s2[r]]++;


            while(r-l+1 > s1.size())
            {
                hash2[s2[l]]--;
                if(hash2[s2[l]] == 0) hash2.erase(s2[l]);
                l++;
            }
            if(r-l+1 == s1.size() && hash1 == hash2) return true;
        }

        return false;
    }
};
