class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto &it : prerequisites){
            
            graph[it[0]].push_back(it[1]);
        }

        for(int i = 0 ; i < graph.size() ; i++){
            for(int &it : graph[i]){
            set<int> visited;
                if(!dfs(it , visited , graph)) return false;
            }
        }
        return true;
    }

    bool dfs(int current , set<int>&visited , vector<vector<int>> &graph){
        visited.insert(current);
        for(auto &it : graph[current]){
            if(visited.count(it) || !dfs(it , visited , graph)) return false;
        }
        return true;
    }
};
