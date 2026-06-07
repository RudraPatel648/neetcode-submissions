class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (endWord.empty() || find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }
        unordered_map<string, vector<string>> hash;
        wordList.push_back(beginWord);
        for (int i = 0; i < wordList.size(); i++) {
            string baseString = wordList[i];
            for (int j = 0; j < wordList[i].size(); j++) {
                string currentString = baseString.substr(0, j) + "*" + baseString.substr(j + 1);
                hash[currentString].push_back(baseString);
            }
        }

        unordered_set<string> visited{beginWord};
        queue<string> q;
        q.push(beginWord); int res = 1;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string baseString = q.front();
                q.pop();
                if(baseString == endWord) return res;
                for (int j = 0; j < baseString.size(); j++) {
                    string currentString = baseString.substr(0, j) + "*" + baseString.substr(j + 1);
                    for(auto &it : hash[currentString]){
                        if(visited.find(it) == visited.end()){
                            visited.insert(it);
                            q.push(it);
                        }
                    }
                }
            }
            res++;
        }

        return 0;
    }
};
