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
    int height(TreeNode* root) {
        if(root == nullptr) return 0;
        
        return max(height(root->left), height(root->right)) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        
        int left_height = height(root->left);
        int right_height = height(root->right);
        
        if(abs(left_height - right_height) > 1) return false;
        
        return isBalanced(root->left) && isBalanced(root->right);
    }
};