class Solution {
public:

    bool isNumber(string &str)
    {
        try{
            int x = stoi(str);
        }
        catch(...){
            return false;
        }
        return true;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string str : tokens){
            if(isNumber(str))
                st.push(stoi(str));
            else{
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();

                if(str == "+")
                    st.push(second + first);
                else if(str == "-")
                    st.push(second - first);
                else if(str == "/")
                    st.push(second / first);
                else 
                    st.push(second * first);
            }

        } 
            return st.top();
    }
};
