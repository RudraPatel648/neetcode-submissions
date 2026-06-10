class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> vec(26,0);
        for(int i = 0 ; i < s.size() ; i++)
        {
            vec[s[i] - 'a'] = i;
        }

        int l = 0 ;
        int r = 0;
        vector<int> ans;

        while(r < s.size()){
            int far = vec[s[l] - 'a'];
            while(r < far){
                r++;
                far = max(far , vec[s[r] - 'a']);
            }
            ans.push_back(r-l+1);
            l = r + 1;
            r = l;
        }

        return ans;
    }
};
