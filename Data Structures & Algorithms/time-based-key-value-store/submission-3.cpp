class TimeMap {
    unordered_map<string , vector<pair<string , int>>> hash;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hash[key].push_back({value , timestamp});
    }
    
    string get(string key, int timestamp) {
        vector<pair<string , int>> &vec = hash[key];
        int low = 0;
        int high = vec.size()-1;
        string res = "";
        while(low <= high){
            int mid = low + (high - low ) / 2;
            if(vec[mid].second <= timestamp) res = vec[mid].first;
            if(vec[mid].second == timestamp) return vec[mid].first;
            if(vec[mid].second < timestamp) low = mid + 1;
            else high = mid - 1;
        }

        return res;
    }
};
