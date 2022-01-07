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
    void traversal(TreeNode* root, vector<TreeNode*>& v) {
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            v.push_back(curr);
            if(curr == nullptr) continue;
            
            q.push(curr->left);
            q.push(curr->right);
        }
        
        return;
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1;
        vector<TreeNode*> v2;
    
        traversal(p, v1);
        traversal(q, v2);
        
        if(v1.size() != v2.size()) return false;
        for(int i = 0; i < v1.size(); i++) {
            if(v1[i] == nullptr && v2[i] == nullptr) continue;
            if((v1[i] != nullptr && v2[i] != nullptr) && v1[i]->val == v2[i]->val) continue;
            return false;
        }
        
        return true;
    }
};