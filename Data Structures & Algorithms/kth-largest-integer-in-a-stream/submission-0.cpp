class KthLargest {
public:
priority_queue<int> pq;
// unordered_set<int> st;
int k;
    KthLargest(int k, vector<int>& nums) {
        for(int it : nums){
            // if(!st.count(it))
            pq.push(it);
            // st.insert(it);
        }
        this->k = k;
    }
    
    int add(int val){
        // if(!st.count(val)){
            pq.push(val);
        //     st.insert(val);
        // }

        priority_queue<int> temp = pq;
        int tempK = k;
        while(tempK > 1){
            temp.pop();
            tempK--;
        }
        return temp.top();   
    }
};
