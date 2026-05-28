class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) return false;

        int l = 0;
        vector<int> hash1(26 , 0);
        for(auto it : s1){
            hash1[it - 'a']++;
        }
        vector<int> hash2(26 , 0);

        for(int r = 0 ; r < s2.size() ; r++){
            hash2[s2[r] - 'a']++;

            if(r-l+1 == s1.size()){
                if(hash1 == hash2) return true;
                hash2[s2[l]-'a']--;
                l++;
            }   
        }

        return false;
    }
};
