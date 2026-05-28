class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin() , stones.end());
        while(!pq.empty() && pq.size() > 1){
            int firstStone = pq.top();
            pq.pop();
            int secondStone = pq.top();
            pq.pop();

            int res = firstStone - secondStone;
            if(res) pq.push(res);
        }
        return (!pq.empty()) ? pq.top() : 0;
    }
};
