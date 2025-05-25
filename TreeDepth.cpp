#include <iostream>
#include <algorithm>

// Definition of a tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to calculate the depth of the tree
int depth(Node* node) {
    if (node == nullptr) {
        return 0; // An empty tree has a depth of 0
    } else {
        // Recursively calculate the depth of the left and right subtrees
        int leftDepth = depth(node->left);
        int rightDepth = depth(node->right);

        // Return the maximum depth of the two subtrees, plus 1 for the current node
        return std::max(leftDepth, rightDepth) + 1;
    }
}

int main() {
    // Example usage:
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    std::cout << "Depth of the tree: " << depth(root) << std::endl; // Output: 3

    // Remember to free the allocated memory to prevent memory leaks
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;
    
    return 0;
}