class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> minHeap;
        vector<vector<pair<int,int>>> graph(n + 1);
        for(auto& time : times)
            graph[time[0]].push_back({time[1] , time[2]});
        vector<int> hash(n + 1 , INT_MAX);
        hash[k] = 0;
        minHeap.push({0 , k});

        while(!minHeap.empty()){
            auto [dis , node] = minHeap.top();
            minHeap.pop();

            for(auto& nei : graph[node]){
                auto [adjnode , edgetime] = nei;

                if(dis + edgetime < hash[adjnode])
                {
                    hash[adjnode] = dis + edgetime;
                    minHeap.push({hash[adjnode] , adjnode});
                }
            }
        }

        int maxEl = *max_element(hash.begin() + 1, hash.end());
        return maxEl == INT_MAX ? -1 : maxEl;
    }
};
