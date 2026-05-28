class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for(int i = 0 ; i  < n - 1 ; i++)
        {
            int secondNumber = target - numbers[i];
            if(!(target - numbers[i] <= numbers[i]))
            {
                int low = i + 1;
                int high = n;

                while(low < high)
                {
                    int mid = low + ((high - low) / 2);
                    if(numbers[mid] == secondNumber) return {i + 1 , mid + 1};
                    if(numbers[mid] < secondNumber) low++;
                    else high --;
                }
            }
        }
        return {0,0};
    }
};
