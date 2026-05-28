class Node {
   public:
    int val;
    int key;
    Node* next;
    Node* prev;

    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LRUCache {
   public:
    unordered_map<int, Node*> hash;
    int capacity;
    // Both are dummy that represents Boundries
    Node* left;
    Node* right;

    LRUCache(int capacity) {
        this->capacity = capacity;
        left = new Node(-1);
        right = new Node(-1);

        left->next = right;
        right->prev = left;
    }

    void add(Node* curr) {
        curr->prev = right->prev;
        curr->next = right;

        right->prev->next = curr;
        right->prev = curr;
    }

    void remove(Node* curr) {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;

        curr->next = NULL;
        curr->prev = NULL;
    }

    int get(int key) {
        if (hash.find(key) != hash.end()) {
            remove(hash[key]);
            add(hash[key]);
            return hash[key]->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (hash.find(key) != hash.end()) {
            hash[key]->val = value;
            remove(hash[key]);
            add(hash[key]);
        } else if (hash.size() < capacity) {
            hash[key] = new Node(value);
            hash[key]->key = key;
            add(hash[key]);
        } else {
            Node* toRemove = left->next;
            hash.erase(toRemove->key);
            remove(toRemove);

            hash[key] = new Node(value);
            hash[key]->key = key;
            add(hash[key]);
        }
    }
};
