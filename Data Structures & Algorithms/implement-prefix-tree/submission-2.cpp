class TrieNode{
    public:
    TrieNode* child[26];
    bool eow;

    TrieNode(){
        for(int i = 0 ; i < 26 ; i++){
            child[i] = NULL;
        }
        eow = false;
    }
};


class PrefixTree {
public:
    TrieNode* root;
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* current = root;

        for(char c : word){
            int i = c-'a';
            if(current->child[i] == NULL){
                current->child[i] = new TrieNode();
            }
            current = current->child[i];
        }
        current->eow = true;
    }
    
    bool search(string word) {
        TrieNode* current = root;

        for(char c : word){
            int i = c - 'a';
            if(!current->child[i]) return false;
            current = current->child[i];
        }

        return current->eow;
    }
    
    bool startsWith(string prefix) {
        TrieNode* current = root;

        for(char c : prefix){
            int i = c - 'a';
            if(!current->child[i]) return false;
            current = current->child[i];
        }

        return true;
    }
};
