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

class Solution {
   public:
    bool traverse(TreeNode* current, TreeNode* target, stack<TreeNode*>& st) {
        if (!current) return false;
        if (current == target || traverse(current->left, target, st) ||
            traverse(current->right, target, st)) {
                st.push(current);
                return true;
            }
        return false;
    }
        

        TreeNode* lowestCommonAncestor(TreeNode * root, TreeNode * p, TreeNode * q) {
            stack<TreeNode*> stP;
            stack<TreeNode*> stQ;

            traverse(root, p, stP);
            traverse(root, q, stQ);

            TreeNode* res = root;
            if (stP.size() > stQ.size()) swap(stP, stQ);

            while (!stP.empty() && !stQ.empty()) {
                if (stP.top() == stQ.top()) {
                    res = stP.top();
                    stP.pop();
                    stQ.pop();
                }
                else{
                    stQ.pop();
                }
            }

            return res;
        }
    };