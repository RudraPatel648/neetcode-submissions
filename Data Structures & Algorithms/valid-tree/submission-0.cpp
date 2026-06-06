class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(!n) return true;

        vector<vector<int>> graph(n);

        for(auto &it : edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }

        unordered_set<int> visit;
        if(!dfs(0 , -1 , visit , graph)) return false;
        return visit.size() == n;
    }

    bool dfs(int current , auto prev , auto&visit , auto& graph ){

        if(visit.count(current)) return false;
        visit.insert(current);
        
        for(auto &it : graph[current]){
            if(it == prev) continue;
            if(!dfs(it , current , visit , graph))
            return false;
        }

        // visit.erase(current);
        return true;
    }
};
