class TrieNode {
   public:
    TrieNode* children[26];
    bool isWord;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isWord = false;
    }

    void addWord(string word) {
        TrieNode* current = this;
        for (char c : word) {
            int i = c - 'a';
            if (!current->children[i]) current->children[i] = new TrieNode();
            current = current->children[i];
        }
        current->isWord = true;
    }
};

class Solution {
   public:
    unordered_set<string> res;
    vector<vector<bool>> visit;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();

        for(auto &str : words){
            root->addWord(str);
        }

        int ROW = board.size();
        int COL = board[0].size();

        visit.assign(ROW, vector<bool>(COL, false));

        for(int r = 0 ; r < ROW ; r++){
            for(int c = 0 ; c < COL ; c++){
                dfs(board , r ,c , root , "");
            }
        }

        return vector<string>(res.begin() , res.end());
    }

    void dfs(auto&board, int r , int c ,TrieNode* node , string word){
        int ROW = board.size();
        int COL = board[0].size();

        if(r < 0 || c < 0 || r >= ROW || c >= COL ||
        visit[r][c] ||  !node->children[board[r][c] - 'a']){
            return;
        }

        visit[r][c] = true;
        node = node->children[board[r][c] - 'a'];
        word += board[r][c];
        if(node->isWord){
            res.insert(word);
        }

        dfs(board , r + 1 , c , node , word);
        dfs(board , r - 1 , c , node , word);
        dfs(board , r , c + 1 , node , word);
        dfs(board , r , c - 1 , node , word);

        visit[r][c] = false;
    }
};
