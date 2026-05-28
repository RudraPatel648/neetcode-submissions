/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        queue<TreeNode*> q;
        q.push(root);
        string s = "";
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            if (!current)
                s.append("#,");
            else
                s.append(to_string(current->val) + ',');

            if (current) {
                q.push(current->left);
                q.push(current->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) return NULL;

        stringstream s(data);
        string str;

        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            getline(s, str, ',');
            if (str == "#") {
                current->left = NULL;
            } else {
                TreeNode* leftNode = new TreeNode(stoi(str));
                current->left = leftNode;
                q.push(leftNode);
            }

            getline(s, str, ',');
            if (str == "#") {
                current->right = NULL;
            } else {
                TreeNode* rightNode = new TreeNode(stoi(str));
                current->right = rightNode;
                q.push(rightNode);
            }

        }
        return root;
    }
};
