class Solution {
   public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        set<pair<int, int>> visited;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> frontiers;
        frontiers.push({0 , {points[0][0] , points[0][1]}});
        int totalcost = 0;
        while(visited.size() != points.size()){
            auto [cost , toPoint] = frontiers.top();
            frontiers.pop();
            auto [x1,y1] = toPoint;

            if(visited.count(toPoint)) continue;
            visited.insert({x1,y1});
            totalcost += cost;

            for(auto &point : points){
                if(visited.count({point[0] , point[1]})) continue;
                int x2 = point[0];
                int y2 = point[1];
                int currcost = abs(x1-x2) + abs(y1-y2);
                frontiers.push({currcost , {x2 , y2}});
            }
        }

        return totalcost;
    }
};
