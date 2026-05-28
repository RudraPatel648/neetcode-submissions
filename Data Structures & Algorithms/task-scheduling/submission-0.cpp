class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> vec(26,0);
        priority_queue<int> pq;
        for(auto it : tasks){
            vec[it-'A']++;
        }
        for(auto it : vec){
            if(it)pq.push(it);
        }

        queue<pair<int,int>> q;
        int time= 0;

        while(!pq.empty() || !q.empty()){
            time++;
            if(pq.empty()){
                time = q.front().second;
            }
            else{
                int count = pq.top() - 1;
                pq.pop();
                if(count) q.push({count , time + n});
            }

            if(!q.empty() && q.front().second == time){
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
