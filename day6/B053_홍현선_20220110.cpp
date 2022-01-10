/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void LRV(Node* curr, vector<int> &v) {
        if(curr == nullptr) return;
        
        for(auto n:curr->children) LRV(n, v);
        
        v.push_back(curr->val);
    }
    
    vector<int> postorder(Node* root) {
        vector<int> v;
        LRV(root, v);
        
        return v;
    }
};