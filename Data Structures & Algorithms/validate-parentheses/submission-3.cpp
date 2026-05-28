class Solution {
public:
    char correctCombination(char ch)
    {
        if(ch == ')') return '(';
        else if(ch == ']') return '[';
        return '{';
    }
    bool isValid(string s) {
        if(s.size() == 1) return false;
        stack<char> st;
        for(char ch : s)
        {
            if(ch =='(' || ch== '[' || ch == '{') st.push(ch);
            else if(st.empty() || st.top() != correctCombination(ch)) return false;
            else st.pop();
        }
        if(!st.empty()) return false;
        return true;
    }
};
