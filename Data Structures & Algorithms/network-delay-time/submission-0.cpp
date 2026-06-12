class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n + 1);
        for (auto& time : times) graph[time[0]].push_back({time[1], time[2]});

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
         vector<int> totaltime(n + 1, INT_MAX);
        totaltime[0] = 0;
        totaltime[k] = 0;

        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();
            int time = current.first;
            int currentNode = current.second;

            for (auto& nei : graph[currentNode]) {
                int adjnode = nei.first;
                int edgetime = nei.second;

                if (time + edgetime < totaltime[adjnode]) {
                    totaltime[adjnode] = time + edgetime;
                    pq.push({totaltime[adjnode], adjnode});
                }
            }
        }
        int ans = *max_element(totaltime.begin() , totaltime.end());
        return (ans == INT_MAX) ? -1 : ans;
    }
};
