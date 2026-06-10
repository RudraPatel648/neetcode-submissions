class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int steps = 0;
        while(r < nums.size() - 1){
            int fur = l + nums[l];
            for(int i = l ; i <= r ; i++){
                fur = max(fur , i + nums[i]);
            }
            l = r;
            r = fur;
            steps++;
        }        
        return steps;
    }
};
