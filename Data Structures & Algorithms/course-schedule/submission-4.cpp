class Solution {
   public:
    vector<vector<int>> graph;
    unordered_set<int> visit;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph.resize(numCourses);
        for (auto& pre : prerequisites) {
            graph[pre[0]].push_back(pre[1]);
        }

        for(int i = 0 ; i < numCourses; i++){
            if(!dfs(i)) return false;
        }

        return true;
    }

    bool dfs(int current){
        if(visit.count(current)) return false;

        visit.insert(current);
        for(auto it : graph[current]){
            if(!dfs(it)) return false;
        }
        visit.erase(current);
        return true;
    }
};
