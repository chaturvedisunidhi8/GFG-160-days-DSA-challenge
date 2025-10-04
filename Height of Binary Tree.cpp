// Structure for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:
    // Function to find the height of a binary tree (in terms of edges)
    int height(Node* node) {
        if (node == nullptr)
            return -1;  // base case: -1 to count edges, not nodes

        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        return std::max(leftHeight, rightHeight) + 1;
    }
};
