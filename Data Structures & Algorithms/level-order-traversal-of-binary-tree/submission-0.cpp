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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
       queue<TreeNode*> q;
       q.push(root);
       vector<vector<int>> ans;
       while(!q.empty()){
            int size = q.size();
            vector<int> currentLevel;

            for(int i = 0 ; i < size ; i++){
                TreeNode* &current = q.front();
                currentLevel.push_back(current->val);
                if(current->left)q.push(current->left);
                if(current->right)q.push(current->right);
                q.pop();
            }
            ans.push_back(currentLevel);
       }  

       return ans;
    }
};
