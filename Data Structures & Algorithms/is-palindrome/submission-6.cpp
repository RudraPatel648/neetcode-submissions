class Solution {
public:
    bool isAlphabet(char ch){
        return(ch >= 'A' && ch <='Z') || (ch>='a' && ch<= 'z') || (ch>='0' && ch <='9');
    }

    bool isPalindrome(string s) {
        int low = 0;
        int high = s.size() - 1;

        while(low < high){
            while(low < high && !isAlphabet(s[high])) high--;
            while(low < high && !isAlphabet(s[low])) low++;
            // if(low>= high) break;
            if(tolower(s[high]) != tolower(s[low])) return false;
            low++;
            high--;            
        }

        return true;
    }
};
