class Solution {
   public:
    int characterReplacement(string s, int k) {
        unordered_set<char> st;
        for (char c : s) {
            st.insert(c);
        }
        int res = 0;
        for (char c : st) {
            int l = 0;
            int count = 0;
            for(int r = 0 ; r < s.size() ; r++) {
                if (s[r] == c) {
                    count++;
                }
                if ((r - l + 1) - count > k) {
                    if (s[l] == c) count--;
                    l++;
                }

                res = max(res, r - l + 1);
            }
        }
        return res;
    }
};
