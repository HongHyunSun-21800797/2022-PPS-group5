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
    void inorder(TreeNode* node, queue<TreeNode*> &q) {
        if(node == nullptr) return;
        
        inorder(node->left, q);
        q.push(node);
        inorder(node->right, q);
        
        return;
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        if(root == nullptr) return nullptr;
        
        queue<TreeNode*> q;
        inorder(root, q);
        root = q.front();
        TreeNode* curr = root;
        q.pop();
        
        
        while(!q.empty()) {
            curr->right = q.front();
            curr->left = nullptr;
            curr = q.front();
            curr->left = nullptr;
            curr->right = nullptr;
            q.pop();
        }
        
        
        return root;
    }
};