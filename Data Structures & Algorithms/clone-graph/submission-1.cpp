/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
   public:
    unordered_map<Node*, Node*> hash;
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        return dfs(node);
    }

    Node* dfs(Node* node) {
        Node* current = new Node(node->val);
        hash[node] = current;
        for (auto& neighbor : node->neighbors) {
            if (hash.find(neighbor) != hash.end())
                current->neighbors.push_back(hash[neighbor]);
            else
                current->neighbors.push_back(dfs(neighbor));
        }

        return current;
    }
};
