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
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<Node*, Node*> hash;
        queue<Node*> q;

        hash[node] = new Node(node->val);
        q.push(node);

        while (!q.empty()) {
            Node* front = q.front();
            q.pop();

            for (auto& nei : front->neighbors) {
                if (!hash.count(nei)) {
                    hash[nei] = new Node(nei->val);
                    q.push(nei);
                }
                hash[front]->neighbors.push_back(hash[nei]);
            }
        }
        return hash[node];
    }
};
