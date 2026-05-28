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
    void traverse(TreeNode* current , int maxi , int &ans){
        if(!current) return;

        if(maxi <= current->val) ans++;
        maxi = max(maxi , current->val);

        traverse(current->left , maxi , ans);
        traverse(current->right , maxi , ans);
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;        
        traverse(root , root->val , ans);
        return ans;
    }
};
