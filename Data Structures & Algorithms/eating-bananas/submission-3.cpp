class Solution {
public:

    int totalHoursReq(vector<int>& piles , int k , int h)
    {
        int hoursPassed = 0;
        for(int bananas : piles)
        {
            if(hoursPassed > h) return hoursPassed;
            if(bananas <= k)
                hoursPassed++;
            else if(bananas % k == 0) hoursPassed += bananas / k;
            else
                hoursPassed += (bananas / k) + 1;
        }
        return hoursPassed;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = INT_MIN;
        // int mini = INT_MAX;
        for(int bananas : piles){
        maxi = max(maxi , bananas);
        // mini = min(mini , bananas);
        }

        int low = 1; //mini;
        int high = maxi;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(totalHoursReq(piles , mid , h) > h) low = mid + 1;
            else high = mid - 1;
        }

        return low;
    }
};
