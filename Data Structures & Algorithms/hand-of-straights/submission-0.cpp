class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int , int> hash;
        for(int i = 0 ; i < hand.size() ; i++){
            hash[hand[i]]++;
        }
        priority_queue<int , vector<int> , greater<int>> minHeap;
        
        for(auto &it : hash){
            minHeap.push(it.first);
        }

        while(!minHeap.empty()){
            int current = minHeap.top();
            for(int i = current; i < current + groupSize ; i++){
                if(hash.find(i) == hash.end()) return false;
                hash[i]--;
                if(hash[i] == 0){
                    if(i != minHeap.top()) return false;
                    minHeap.pop();
                }
            }
        }

        return true;
    }
};
