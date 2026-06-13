class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string , deque<string>> adj;
        for(auto &ticket : tickets)
        adj[ticket[0]].push_back(ticket[1]);
        for(auto &[node , neinodes] : adj)
        sort(neinodes.rbegin() , neinodes.rend());

        vector<string> res;
        dfs("JFK" , res , adj);
        reverse(res.begin() , res.end());
        return res;
    }

    void dfs(string src , vector<string> &res, unordered_map<string , deque<string>> &adj){
        while(!adj[src].empty())
        {
            string current = adj[src].back();
            adj[src].pop_back();
            dfs(current , res , adj);
        }
        res.push_back(src);
    }
};
