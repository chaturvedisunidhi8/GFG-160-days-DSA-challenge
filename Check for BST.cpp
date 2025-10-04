class Solution {
public:
    // Helper function to validate BST
    bool isBSTUtil(Node* node, int min, int max) {
        if (node == NULL)
            return true;

        // Check current node value against min and max
        if (node->data <= min || node->data >= max)
            return false;

        // Recursively check left and right subtrees with updated ranges
        return isBSTUtil(node->left, min, node->data) &&
               isBSTUtil(node->right, node->data, max);
    }

    // Main function to check if tree is BST
    bool isBST(Node* root) {
        return isBSTUtil(root, INT_MIN, INT_MAX);
    }
};
