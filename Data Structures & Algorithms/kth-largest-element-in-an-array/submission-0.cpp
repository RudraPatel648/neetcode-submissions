class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int , vector<int> , greater<int>> minHeap;

        for(int &it : nums)
        {
            if(minHeap.size() < k){
                minHeap.push(it);
            }
            else if (it > minHeap.top()){
                minHeap.pop();
                minHeap.push(it);
            }
        }
        return minHeap.top();
    }
};
