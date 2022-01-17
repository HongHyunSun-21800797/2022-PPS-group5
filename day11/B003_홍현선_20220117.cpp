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
    void accum_left(TreeNode* curr, int& accum) {
        if(curr->left != nullptr && curr->left->left == nullptr && curr->left->right == nullptr) accum += curr->left->val;
            
        return;
    }
    
    void dfs(TreeNode* curr, int& accum) {
        accum_left(curr, accum);
        
        if(curr->left != nullptr) dfs(curr->left, accum);
        if(curr->right != nullptr) dfs(curr->right, accum);
        
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int accum = 0;
        
        dfs(root, accum);
        
        return accum;
    }
};