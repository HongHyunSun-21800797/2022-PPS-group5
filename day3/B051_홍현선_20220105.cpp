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
    vector<string> binaryTreePaths(TreeNode* root) {
        stack<pair<TreeNode*, string>> s;
        s.push(make_pair(root, to_string(root->val)));
        vector<string> paths;
        
        while(!s.empty()) {
            TreeNode* curr = s.top().first;
            string path = s.top().second;
            s.pop();
            
            if(curr->left != nullptr) s.push(make_pair(curr->left, path+"->"+to_string(curr->left->val)));
            if(curr->right != nullptr) s.push(make_pair(curr->right, path+"->"+to_string(curr->right->val)));
            if(curr->left == nullptr && curr->right == nullptr) paths.push_back(path);
        }
        return paths;
    }
};