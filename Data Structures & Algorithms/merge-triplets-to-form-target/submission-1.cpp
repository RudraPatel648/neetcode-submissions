class Solution {
   public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<bool> found(3, false);
        auto& t = triplets;
        int n = t.size();
        for (int i = 0; i < 3; i++) {
            for (int r = 0; r < n; r++) {
                if (found[i]) break;
                if (t[r][i] == target[i] && t[r][0] <= target[0] && t[r][1] <= target[1] &&
                    t[r][2] <= target[2]) {
                    if (t[r][0] == target[0]) found[0] = true;
                    if (t[r][1] == target[1]) found[1] = true;
                    if (t[r][2] == target[2]) found[2] = true;
                    break;
                }
            }
        }

        return (found[0] && found[1] && found[2]);
    }
};
