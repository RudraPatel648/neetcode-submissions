class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for(int i = 0 ; i  < n - 1 ; i++)
        {
            int secondNumber = target - numbers[i];
            if(!(target - numbers[i] <= numbers[i]))
            {
                for(int j = i + 1 ; j < n ; j++)
                {
                    if(numbers[j] == secondNumber)
                    return {i+1 , j+1};
                }
            }
        }
        return {0,0};
    }
};
