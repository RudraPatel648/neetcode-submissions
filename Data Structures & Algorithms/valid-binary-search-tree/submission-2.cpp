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
    bool traverse(TreeNode* current , long long low , long long high){
        if(!current) return true;

        if(current->val <= low || current->val >= high) return false;

        bool left = traverse(current->left , low , current->val);
        bool right = traverse(current->right , current->val , high);

        return left && right;
    }

    bool isValidBST(TreeNode* root) {
        long long low = LLONG_MIN;
        long long high = LLONG_MAX;

        return traverse(root , low , high);
    }
};
