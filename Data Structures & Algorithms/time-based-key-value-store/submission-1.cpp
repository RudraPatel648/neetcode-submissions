class TimeMap {
private:
    map<string , vector<pair<string,int>>> mpp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({value , timestamp});
    }
    
    string get(string key, int timestamp) {
        int low = 0;
        int high = mpp[key].size() - 1;
        string ans = "";
        while(low <= high){
            int mid = low + (high - low) / 2;
            auto current = mpp[key][mid];
            if(current.second <= timestamp)
            {
                ans = current.first;
                low = mid + 1;
            }
            else 
                high = mid - 1;
        }
        return ans;
    }
};
