#include <iostream>

struct TreeNode {
    int data;
    TreeNode *parent;
    TreeNode *left;
    TreeNode *right;
};

TreeNode* make_tree_node(int data) {
    TreeNode *tNode = new TreeNode();
    tNode->data = data;
    tNode->left = NULL;
    tNode->right = NULL;
    return tNode;
}

int main() {
    return 0;
}