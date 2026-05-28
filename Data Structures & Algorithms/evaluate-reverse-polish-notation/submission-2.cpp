class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st; 
        for(int i = 0 ; i < tokens.size() ; i++){
            if(tokens[i] == "+" ||
            tokens[i] == "-" ||
            tokens[i] == "*" ||
            tokens[i] == "/" ){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();

                int sum;
                if(tokens[i] == "+") sum = second + first;
                if(tokens[i] == "-") sum = second - first;
                if(tokens[i] == "*") sum = second * first;
                if(tokens[i] == "/") sum = second / first;
                st.push(sum);
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
