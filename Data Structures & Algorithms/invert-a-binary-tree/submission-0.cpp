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
    void invert(TreeNode* current){
        if(!current) return;

        invert(current->left);
        TreeNode* currentLeft = current->left;
        current->left = current->right;
        current->right = currentLeft;
        invert(current->left);
    }
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};
