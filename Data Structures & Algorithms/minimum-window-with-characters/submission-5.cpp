class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int low = 0;
        int high = 0;

        unordered_map<char , int> hashT;
        for(auto it : t) hashT[it]++;

        int have = 0;
        int need = hashT.size();
        string res = "";

        unordered_map<char , int> hash;
        while(high < n ){
            hash[s[high]]++;
            if(hash[s[high]] && hash[s[high]] == hashT[s[high]]) have++;
            while(have == need){
                if(res == "" || high - low + 1 < res.size()){
                    res = s.substr(low , high - low + 1);
                }

                hash[s[low]]--;
                if(hash[s[low]] < hashT[s[low]]){
                    have--;
                }
                low++;
            }
            high++;
        }

        return res;
    }
};
