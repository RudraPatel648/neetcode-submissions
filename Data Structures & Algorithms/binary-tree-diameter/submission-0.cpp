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
    int traverse(TreeNode* current , int &res){
        if(!current) return 0;
        int leftDepth = traverse(current->left , res);
        int rightDepth = traverse(current->right , res);
        res = max(leftDepth + rightDepth + 1, res);
        return max(leftDepth , rightDepth) + 1;        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        traverse(root , res);
        return res - 1;
    }
};
