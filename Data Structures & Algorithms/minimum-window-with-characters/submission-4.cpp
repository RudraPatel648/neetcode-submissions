class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";

        unordered_map<char , int> hashT;
        unordered_map<char , int> hashS;

        for(auto c : t){
            hashT[c]++;
        }

        int have = 0;
        int need = hashT.size();
        int l = 0;

        int minLen = INT_MAX;
        int start = -1;
        for(int r = 0 ; r < s.size() ; r++){
            hashS[s[r]]++;

            if(hashT.find(s[r]) != hashT.end() && hashS[s[r]] == hashT[s[r]]) have++;

            while(have == need){
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    start = l;
                }
                hashS[s[l]]--;
                if(hashT.find(s[l]) != hashT.end() && hashS[s[l]] < hashT[s[l]]) have--;
                l++;
            }
        }

        if(start == -1) return "";
        return s.substr(start , minLen);
    }
};
