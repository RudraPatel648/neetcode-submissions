class MedianFinder {
public:
    priority_queue<int> smallerHeap;
    priority_queue<int , vector<int> , greater<int>> largerHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        smallerHeap.push(num);
        if(!largerHeap.empty() && smallerHeap.top() > largerHeap.top()){
            largerHeap.push(smallerHeap.top());
            smallerHeap.pop();
        }
        if(smallerHeap.size() > largerHeap.size()){
            largerHeap.push(smallerHeap.top());
            smallerHeap.pop();
        }
        if (largerHeap.size() > smallerHeap.size()){
            smallerHeap.push(largerHeap.top());
            largerHeap.pop();
        }
    }
    
    double findMedian() {
        if(smallerHeap.size() == largerHeap.size()){
            return (smallerHeap.top() + largerHeap.top()) / 2.0;
        }
        else if (smallerHeap.size() > largerHeap.size()){
            return (double)smallerHeap.top();
        }
        else{
            return (double)largerHeap.top();
        }
    }
};
