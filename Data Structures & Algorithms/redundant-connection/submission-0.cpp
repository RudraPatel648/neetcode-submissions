class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> visit;
    unordered_set<int> cycle;
    int cycleStart;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        graph.resize(n+1);
        visit.resize(n+1 , false);
        cycleStart =-1;

        for(auto &edge:edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        dfs(1,-1);

        for(int i = n -1 ; i>=0 ; i--){
            int u = edges[i][0];
            int v = edges[i][1];

            if(cycle.count(u)&&cycle.count(v)){
                return {u,v};
            }
        }
        return {};
    }

    bool dfs(int current, int prev){
        if(visit[current]){
            cycleStart = current;
            return true;
        }

        visit[current] = true;
        for(auto&nei : graph[current]){
            if(nei==prev)continue;
            if(dfs(nei,current)){
                if(cycleStart != -1) cycle.insert(nei);
                if(current==cycleStart){
                    cycleStart=-1;
                }
                return true;
            }
        }
        return false;
    }
};
