class KthLargest {
public:
priority_queue<int , vector<int> , greater<int>> minHeap;
int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int it : nums){
            if(minHeap.size() < k){
                minHeap.push(it);
            }
            else if(it > minHeap.top()){
                minHeap.pop();
                minHeap.push(it);
            }
        }  
    }
    
    int add(int val) {
        if(minHeap.size() < k){
            minHeap.push(val);
        }
        else if(val > minHeap.top()){
            minHeap.pop();
            minHeap.push(val);
        }
        return minHeap.top();
    }
};
