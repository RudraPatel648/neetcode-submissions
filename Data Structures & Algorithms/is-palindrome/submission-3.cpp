class Solution {
public:
    bool checkAlphaNumerical(char& ch)
    {
        return ((ch >= 'a' && ch <= 'z') || (ch>='A' && ch<= 'Z') || (ch >= '0' && ch <= '9'));
    }

    bool isPalindrome(string s) {
        int low = 0;
        int high = s.size() - 1;

        while(low < high)
        {
            while(low < high && !checkAlphaNumerical(s[low])) low++;
            while(low < high && !checkAlphaNumerical(s[high])) high--;
            if(low > high) return false;

            if(tolower(s[low]) != tolower(s[high]))
            return false;

            low++;
            high--;
        }    

        return true;
    }
};
