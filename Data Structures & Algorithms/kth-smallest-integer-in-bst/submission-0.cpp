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
    void traverse(TreeNode* current , vector<int> &ans , int k){
        if(ans.size() > k) return;
        if(!current) return;

        if(current->left) traverse(current->left , ans , k);
        ans.push_back(current->val);
        if(current->right) traverse(current->right , ans , k);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        traverse(root , ans , k);
        return ans[k-1];
    }
};
