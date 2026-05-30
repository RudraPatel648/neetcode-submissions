class TrieNode {
   public:
    TrieNode* child[26];
    bool eow;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
        eow = false;
    }
};

class WordDictionary {
   public:
    TrieNode* root;
    WordDictionary() { root = new TrieNode(); }

    void addWord(string word) {
        TrieNode* current = root;
        for (char c : word) {
            int i = c - 'a';
            if (current->child[i] == NULL) {
                current->child[i] = new TrieNode();
            }
            current = current->child[i];
        }
        current->eow = true;
    }

    bool search(string word) {
        return dfs(0 , word , root);
    }

    bool dfs(int j , string word, TrieNode* root){
        TrieNode* current = root;
        for(int i = j ; i < word.size() ; i++){
            char c = word[i];

            if(c == '.'){

                for(auto chld : current->child){
                    if(chld && dfs(i + 1 , word , chld)){
                        return true;
                    }
                }
                return false;
            }

            else{
                if(current->child[c-'a'] == NULL)
                    return false;
                current = current->child[c-'a'];
            }
        }

        return current->eow;
    }
};
