class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char , int> hash;
        for(char ch : s)
        hash[ch]++;

        for(char ch : t){
            if(hash[ch] == 0) return false;
            else hash[ch]--;
        }

        return true;
    }
};
