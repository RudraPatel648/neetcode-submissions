class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto &it : edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }

        unordered_set<int> visit;
        int components = 0;

        for(int i = 0 ; i < n ; i++){
            
            if(visit.count(i)) continue;
            components++;
            for(auto &it : graph[i]){
                dfs(it , visit , graph);
            }
        }

        return components;
    }

    void dfs(int current , auto&visit , auto&graph){
        if(visit.count(current)) return;
        visit.insert(current);
        for(auto &it : graph[current]){
            if(it == current) continue;
            dfs(it , visit , graph);
        }
    }
};
