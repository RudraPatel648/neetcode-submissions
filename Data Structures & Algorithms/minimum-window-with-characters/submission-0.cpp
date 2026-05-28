class Solution {
public:
    bool compare(unordered_map<char , int>& hashS,unordered_map<char , int>& hashT){
        for(auto it : hashT){
            if(hashS.find(it.first) == hashS.end() || hashS[it.first] < hashT[it.first]) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";
        unordered_map<char , int> hashT;
        unordered_map<char , int> hashS;
        int l = 0;

        // string res = s;

        int minLen = INT_MAX;
        int start = -1;

        for(auto it : t){
            hashT[it]++;
        }

        for(int r = 0 ; r < s.size() ; r++){
            hashS[s[r]]++;
            
            while(compare(hashS, hashT)){
                if(r-l+1 < minLen){
                    minLen = r - l + 1;
                    start = l;
                }
                hashS[s[l]]--;
                l++;
            }
        }

        if(start == -1) return "";
        return s.substr(start , minLen);
    }
};
