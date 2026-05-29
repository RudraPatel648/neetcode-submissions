class Solution {
   public:
    string getAlpha(char digit) {
        string ans;
        switch (digit) {
            case '2':
                ans = "abc";
                break;
            case '3':
                ans = "def";
                break;
            case '4':
                ans = "ghi";
                break;
            case '5':
                ans = "jkl";
                break;
            case '6':
                ans = "mno";
                break;
            case '7':
                ans = "pqrs";
                break;
            case '8':
                ans = "tuv";
                break;
            case '9':
                ans = "wxyz";
                break;
            default:
                ans = "";
        }
        return ans;
    }

    void backtrack(string &digits , vector<string> &ans, string &current, int index )
    {
        if(index >= digits.size()){
            ans.push_back(current);
        }

        string currentString = getAlpha(digits[index]);
        for(int i = 0 ; i < currentString.size() ; i++){
            current.push_back(currentString[i]);
            backtrack(digits , ans , current , index + 1);
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(!digits.size()) return {};
        vector<string> ans;
        string current = "";
        backtrack(digits , ans , current , 0);
        return ans;
    }
};
