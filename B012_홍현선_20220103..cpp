#include <iostream>

using namespace std;

struct node{
    int val;
    node* left;
    node* right;
};

node* insert(node *root, int val) {
    if(root == nullptr) {
        node* n = new node;
        n -> val = val;
        n -> left = nullptr;
        n -> right = nullptr;
        return n;
    }

    if(val < root->val) root->left = insert(root->left, val);
    else if(val > root->val) root->right = insert(root->right, val);
    
    return root;
}

void postorder(node* Node) {
    if(Node == nullptr) return;

    postorder(Node->left);
    postorder(Node->right);
    cout << Node->val << "\n";

    return;
}

void end(node *root) {
    if(root == nullptr) return;

    end(root -> left);
    end(root -> right);
    delete root;
}

int main() {

    int val;
    node * root = nullptr;

    while(cin >> val) {
        if(val == EOF) break;
        root = insert(root, val);
    }
    
    postorder(root);

    end(root);

    return 0;
}