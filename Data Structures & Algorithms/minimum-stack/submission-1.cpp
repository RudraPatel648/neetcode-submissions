class MinStack {
public:
    stack<int> stOriginal;
    stack<int> stDuplicate;
    MinStack() {
    }
    
    void push(int val) {
        stOriginal.push(val);
        stDuplicate.push(min(val , (stDuplicate.empty()) ? val : stDuplicate.top()));
    }
    
    void pop() {
        stOriginal.pop();
        stDuplicate.pop();
    }
    
    int top() {
        return stOriginal.top();
    }
    
    int getMin() {
        return stDuplicate.top();
    }
};
