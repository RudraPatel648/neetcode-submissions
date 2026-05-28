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
void traverse(TreeNode* current , unordered_set<int> &s , int count , vector<int> &ans){
        if(!current) return;

        if(!s.count(count)){
            ans.push_back(current->val);
            s.insert(count);
        }
        count++;
        traverse(current->right , s , count , ans);
        traverse(current->left , s , count , ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        unordered_set<int> s;
        traverse(root , s , 1 , ans);
        return ans;
    }
};
