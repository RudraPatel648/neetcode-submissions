class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for(string str : strs)
        {
            s += str + "gand";
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        int i = 0;

        while(true)
        {
            int pos = s.find("gand" , i);

            if(pos==-1)
            {
                // ans.push_back(s.substr(i));
                break;
            }

            ans.push_back(s.substr(i , pos - i));

            i = pos + 4;
        }

        return ans;
    }
};
