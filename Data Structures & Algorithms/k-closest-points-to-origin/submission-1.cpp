class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<float,vector<int>>> pq;
        for(vector<int> vec : points){
            int &x1 = vec[0];
            int &y1 = vec[1];
            float currentDistance = sqrt(x1*x1 + y1*y1);

            if(pq.size() < k){
                pq.push({currentDistance , {vec[0],vec[1]}});
                continue;
            }
            int x2 = pq.top().second[0];
            int y2 = pq.top().second[1];
            float topDistance = sqrt(x2*x2 + y2*y2);

            if(currentDistance < topDistance){
                pq.pop();
                pq.push({currentDistance,{vec[0] , vec[1]}});
            }
        }

        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
