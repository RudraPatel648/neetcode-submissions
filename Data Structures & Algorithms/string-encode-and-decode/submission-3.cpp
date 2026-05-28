class Solution {
public:

    string encode(vector<string>& strs) {
        string str = "";
        for(auto it : strs)
        {
            str += to_string(it.size()) + '#' + it;
        }
        return str;
    }

    vector<string> decode(string s) {
        vector<string> vec;
        int i = 0;
        while(i < s.size())
        {
            int j = i;
            string lenStr = "";
            while(s[j] != '#')
            {
                lenStr += s[j];
                j++;
            }
            int length = stoi(lenStr);
            string current = s.substr(j + 1 , length);
            vec.push_back(current);
            i = j + length + 1;
        }
        return vec;
    }
};
