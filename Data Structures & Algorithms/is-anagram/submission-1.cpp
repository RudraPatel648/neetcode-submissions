class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> hash(26,0);
        for(char c : s)
        hash[c - 'a']++;

        for(char c : t)
        {
            if(hash[c - 'a'] == 0)
            return false;
            hash[c-'a']--;
        }

        for(int i : hash)
        {
            if(i != 0) return false;
        }
        return true;
    }
};
