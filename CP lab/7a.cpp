#include <iostream>

// Node structure for the binary tree
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Binary Tree class
class BinaryTree {
private:
    TreeNode* root;

    // Function to insert a node into the binary tree
    TreeNode* insertNode(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->data) {
            node->left = insertNode(node->left, value);
        } else if (value > node->data) {
            node->right = insertNode(node->right, value);
        }

        return node;
    }

    // Function to find the node with the minimum value in a subtree
    TreeNode* findMinNode(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Function to delete a node from the binary tree
    TreeNode* deleteNode(TreeNode* node, int value) {
        if (node == nullptr) {
            return node;
        }

        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        } else {
            // Node with one child or no child
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            TreeNode* temp = findMinNode(node->right);

            // Copy the inorder successor's data to this node
            node->data = temp->data;

            // Delete the inorder successor
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    // Function to perform in-order traversal
    void inOrderTraversal(TreeNode* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            std::cout << node->data << " ";
            inOrderTraversal(node->right);
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    // Function to insert a node into the binary tree
    void insert(int value) {
        root = insertNode(root, value);
    }

    // Function to delete a node from the binary tree
    void remove(int value) {
        root = deleteNode(root, value);
    }

    // Function to perform in-order traversal
    void traverseInOrder() {
        std::cout << "In-Order Traversal: ";
        inOrderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    BinaryTree binaryTree;

    // Insert nodes into the binary tree
    binaryTree.insert(50);
    binaryTree.insert(30);
    binaryTree.insert(70);
    binaryTree.insert(20);
    binaryTree.insert(40);
    binaryTree.insert(60);
    binaryTree.insert(80);

    // Perform in-order traversal
    binaryTree.traverseInOrder();

    // Delete a node from the binary tree
    binaryTree.remove(30);

    // Perform in-order traversal after deletion
    binaryTree.traverseInOrder();

    return 0;
}
