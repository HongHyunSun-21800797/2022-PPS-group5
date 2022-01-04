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
    bool isCousins(TreeNode* root, int x, int y) {
        int x_depth;
        int y_depth;
        TreeNode* x_parent = nullptr;
        TreeNode* y_parent = nullptr;
        queue<pair<int, pair<TreeNode*, TreeNode*>>> q;
        q.push(make_pair(0, make_pair(nullptr, root)));
        
        
        while(!q.empty()) {
            int depth = q.front().first;
            TreeNode* parent = q.front().second.first;
            TreeNode* current = q.front().second.second;
            q.pop();
            
            if(current->val == x) {
                x_depth = depth;
                x_parent = parent;
                }
            else if(current->val == y) {
                y_depth = depth;
                y_parent = parent;
            }
            
            if(current->left != nullptr) q.push(make_pair(depth+1, make_pair(current, current->left)));
            if(current->right != nullptr) q.push(make_pair(depth+1, make_pair(current, current->right)));
        }
        
        if(x_depth == y_depth && x_parent != y_parent) return true; 
        
        return false;
    }
};