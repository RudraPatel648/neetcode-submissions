class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> hash(26,0);
        for (auto& it : tasks) {
            hash[it - 'A']++;
        }
        priority_queue<int> pq;
        for (auto& it : hash) {
            if(it)pq.push(it);
        }
        queue<pair<int, int>> q;
        int time = 0;
        while (!pq.empty() || !q.empty()) {
            time++;
            if (pq.empty()) {
                time = q.front().second;
            }

            else{
                int count = pq.top() - 1;
                pq.pop();
                if (count > 0) q.push({count, time + n});
            }

            if (!q.empty() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
