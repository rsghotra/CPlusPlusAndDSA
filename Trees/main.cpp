#include <iostream>
using namespace std;

struct Node {
    Node* parent;
    Node* left;
    Node* right;
    int data;
};

Node* make_new_tree_node(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    return 0;
}