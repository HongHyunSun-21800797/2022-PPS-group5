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
    int height(TreeNode* node) {
        if(node == nullptr) return 0;
        int left = height(node->left);
        int right = height(node->right);
        
        return max(left, right) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        
        int curr_length = height(root->left) + height(root->right);
        int left_length = diameterOfBinaryTree(root->left);
        int right_length = diameterOfBinaryTree(root->right);
        
        return max(max(left_length, right_length), curr_length);
    }
};