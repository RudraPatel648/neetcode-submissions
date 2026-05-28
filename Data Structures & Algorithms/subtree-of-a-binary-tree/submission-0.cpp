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
    bool check(TreeNode* p , TreeNode* q){
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val != q->val) return false;

        bool left = check(p->left , q->left);
        bool right = check(p->right , q->right);
        return left&&right;
    }
    bool traverse(TreeNode* current , TreeNode* target){
        if(!current) return false;

        if(current->val == target->val && check(current , target)) return true;

        bool left = traverse(current->left , target);
        bool right = traverse(current->right , target);
        return left || right;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return traverse(root , subRoot);
    }
};
