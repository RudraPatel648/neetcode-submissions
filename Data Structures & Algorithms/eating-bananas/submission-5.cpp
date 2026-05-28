class Solution {
public:
    int hoursNeeded(vector<int>& piles , int h , int k){
        int totalHours = 0;

        for(int bananas : piles){
            if(totalHours > h) break;
            totalHours +=  (bananas <= k) ? 1 : bananas/k + (bananas%k!=0);
        }
        
        return totalHours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;
        while(low<= high){
            int mid = low + (high- low) / 2;
            if(hoursNeeded(piles, h , mid) <= h){
                ans = min(ans,mid);
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }   

        return ans;
    }
};
