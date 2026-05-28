class Twitter {
public:
    priority_queue<pair<int , pair<int , int>>> pq;
    unordered_map<int , unordered_set<int>> users;
    int time = 0;
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        pq.push({time++ , {tweetId , userId}});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<pair<int , pair<int,int>>> dpq = pq;

        while(!dpq.empty() && ans.size() < 10){
            int tweetId = dpq.top().second.first;
            int tweetUserId = dpq.top().second.second;

            if(tweetUserId==userId || users[userId].count(tweetUserId)){
                ans.push_back(tweetId);
            } 
            dpq.pop();
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        users[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        users[followerId].erase(followeeId);
        
    }
};
