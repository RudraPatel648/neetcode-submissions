class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedString = "";
        for(string str : strs)
            encodedString += to_string(str.size()) + '#' + str;
        return encodedString;
    }

    vector<string> decode(string s) {
        int i = 0;
        vector<string> vec;
        while(i < s.size())
        {
            int j = i;
            while(s[j] != '#')
            j++;
            int length = stoi(s.substr(i , j - i));
            vec.push_back(s.substr(j + 1 ,length));
            i = j + 1 + length;
        }
        return vec;
    }
};
