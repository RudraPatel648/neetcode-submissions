class Solution {
public:
    vector<vector<int>> graph;
    set<int> visiting;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph.resize(numCourses);
        for(auto it : prerequisites){
            graph[it[0]].push_back(it[1]);
        }

        for(int i = 0; i < numCourses; i++){
            if(!dfs(i)) return false;
        }

        return true;
    }

    bool dfs(int current){
        if(visiting.count(current)) return false;
        if(graph[current].empty()) return true;

        visiting.insert(current);
        for(auto &it : graph[current]){
            if(!dfs(it)) return false;
        }
        visiting.erase(current);
        graph[current].clear();
        return true;
    }
};
