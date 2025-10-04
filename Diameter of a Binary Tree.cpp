class Solution {
    int maxDiameter = 0;
    int height(Node* node) {
        if (node == NULL)
            return 0;
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        maxDiameter = std::max(maxDiameter, leftHeight + rightHeight);
        return 1 + std::max(leftHeight, rightHeight);
    }
public:
    int diameter(Node* root) {
        height(root);
        return maxDiameter;
    }
};
