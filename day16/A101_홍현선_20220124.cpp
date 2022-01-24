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
    void inorder(TreeNode* node, int& accum, int low, int high) {
        if(node->left != nullptr) inorder(node->left, accum, low, high);
        if(node->val >= low && node->val <= high) accum+=node->val;
        if(node->right != nullptr) inorder(node->right, accum, low, high);
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        int result = 0;
        inorder(root, result, low, high);
        
        return result;
    }
};