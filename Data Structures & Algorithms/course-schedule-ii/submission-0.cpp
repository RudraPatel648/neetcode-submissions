class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto &it : prerequisites){
            graph[it[0]].push_back(it[1]);
        }

        vector<int> output;
        unordered_set<int> visit;
        unordered_set<int> cycle;

        for(int i = 0 ; i < numCourses ; i++){
            if(!dfs(i , visit , cycle , output , graph)) return {};
        }
        return output;
    }

    bool dfs(int course , auto& visit , auto& cycle , auto& output , auto& graph){
        if(cycle.count(course)) return false;
        if(visit.count(course)) return true;

        cycle.insert(course);
        if(!graph[course].empty()){
            for(auto& it : graph[course]){
                if(!dfs(it , visit , cycle , output , graph)) return false;
            }
        }
        cycle.erase(course);
        visit.insert(course);
        output.push_back(course);
        return true;
    }
};
