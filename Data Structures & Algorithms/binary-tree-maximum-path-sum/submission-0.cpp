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
    int res;

    int dfs(TreeNode* root){
        if(!root) return 0;

        int left = dfs(root->left);
        left = max(left , 0);
        int right = dfs(root->right);
        right = max(right , 0);

        res = max(res , left + right + root->val);

        return root->val + max(left , right);
    }

    int maxPathSum(TreeNode* root) {
        res = root->val;
        dfs(root);
        return res;
    }
};
