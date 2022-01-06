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
    bool visit[20001] = {false, };
    
    int hash(int n) {
        if(n < 0) return -n+10000;
        return n;
    }
    
    int isRange(int n) {
        if(-10000 <=n && n <= 10000) return true;
        return false;
    }
    
    bool findTarget(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        visit[hash(root->val)] = true;
        
        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            
            if(curr->left != nullptr) {
                if(isRange(k - curr->left->val) && visit[hash(k - curr->left->val)]) return true;
                visit[hash(curr->left->val)] = true;
                q.push(curr->left);
            }
            if(curr->right != nullptr) {
                if(isRange(k - curr->right->val) && visit[hash(k- curr->right->val)]) return true;
                visit[hash(curr->right->val)] = true;
                q.push(curr->right);
            } 
        }
        
        return false;
    }
};