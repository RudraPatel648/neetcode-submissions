class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int ans = 0;
        unordered_set<char> st;

        while(r < s.size()){            
            while(st.count(s[r])){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            ans = max(ans , r - l + 1);
            r++;
        }

        ans = max(ans , r-l);
        return ans;
    }
};
