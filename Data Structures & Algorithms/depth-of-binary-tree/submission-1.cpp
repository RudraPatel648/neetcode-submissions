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
    int traverse(TreeNode* current){
        if(!current) return 0;
        int leftCount = traverse(current->left);
        int rightCount = traverse(current->right);

        return max(leftCount , rightCount) + 1;
    }
    int maxDepth(TreeNode* root) {
        return traverse(root);
    }
};
