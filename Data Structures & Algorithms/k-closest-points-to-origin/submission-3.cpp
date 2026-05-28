class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> pq;
        for(vector<int> vec : points){
            int &x1 = vec[0];
            int &y1 = vec[1];
            int currentDistance = x1*x1 + y1*y1;

            if(pq.size() < k){
                pq.push({currentDistance,vec[0],vec[1]});
                continue;
            }
            int topDistance = pq.top()[0];
            if(currentDistance < topDistance){
                pq.pop();
                pq.push({currentDistance,vec[0] , vec[1]});
            }
        }

        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back({pq.top()[1] , pq.top()[2]});
            pq.pop();
        }
        return ans;
    }
};
