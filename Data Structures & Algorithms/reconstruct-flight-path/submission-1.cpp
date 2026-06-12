class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string , vector<string>> adj;
        for(auto &ticket : tickets)
        adj[ticket[0]];
        sort(tickets.begin() , tickets.end());
        for(auto &ticket : tickets)
        adj[ticket[0]].push_back(ticket[1]);

        vector<string> res = {"JFK"};
        dfs("JFK" , adj , res , tickets.size() + 1);
        return res;    
    }
    bool dfs(string src , unordered_map<string , vector<string>> &adj , vector<string>&res , int targetLength){
        if(res.size() == targetLength) return true;
        if(adj.find(src) == adj.end()) return false;

        // vector<string> temp = adj[src];
        for(int  i = 0 ; i < adj[src].size() ; i++){
            string current = adj[src][i];
            res.push_back(current);
            adj[src].erase(adj[src].begin() + i);
            if(dfs(current , adj , res,  targetLength)) return true;
            res.pop_back();
            adj[src].insert(adj[src].begin() + i , current);
        }

        return false;
    }
};
