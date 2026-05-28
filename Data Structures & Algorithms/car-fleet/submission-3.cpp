class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double> st;

        vector<pair<int,int>> cars;

        for(int i = 0; i < position.size(); i++){
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end(), greater<pair<int,int>>());

        int n = position.size();
        for(int i = 0 ; i < n ; i++){
            double reachAt = (double)(target - cars[i].first) / cars[i].second;
            if(!st.empty() && reachAt < st.top()) reachAt = st.top();
            if(st.empty() || reachAt != st.top()) st.push(reachAt);
        }
        return st.size();
    }
};
