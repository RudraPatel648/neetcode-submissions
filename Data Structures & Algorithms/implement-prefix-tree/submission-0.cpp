class TrieNode{
public:
    TrieNode* children[26];
    bool endOfWord;
    TrieNode(){
        for(int i = 0 ; i < 26 ; i++){
            children[i] = nullptr;
        }
        endOfWord = false;
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
            if(!current->children[c-'a']){
                current->children[c-'a'] = new TrieNode();
            }
            current = current->children[c-'a'];
        }

        current->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* current = root;

        for(char c : word){
            if(!current->children[c-'a']) return false;
            current = current->children[c-'a'];
        }    

        return current->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* current = root;

        for(char c : prefix){
            if(!current->children[c-'a']) return false;
            current = current->children[c-'a'];
        }    
        return true;
    }
};
