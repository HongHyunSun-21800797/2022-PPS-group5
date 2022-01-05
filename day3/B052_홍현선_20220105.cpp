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
    int findTilt(TreeNode* root) {
        if(root == nullptr) return 0;
        
        int tilt = findTilt(root->left) + findTilt(root->right);
        int left = 0; // sum of left subtree
        int right = 0; // sum of right subtree
        
        if(root->left != nullptr) left = root->left->val;
        if(root->right != nullptr) right = root->right->val;
        root->val = root->val + left + right; // renew current value into sum of all the subtree
        
        return abs(left-right) + tilt;
    }
};