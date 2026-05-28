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
    int traverse(TreeNode* current , int count){
        if(!current) return count++;
        int leftCount = traverse(current->left , count);
        int rightCount = traverse(current->right , count);

        return max(leftCount , rightCount) + 1;
    }
    int maxDepth(TreeNode* root) {
        return traverse(root , 0);
    }
};
