class Solution {
public:
    void inorderHelper(Node* root, vector<int>& res) {
        if (root == nullptr) return;

        // Traverse left subtree
        inorderHelper(root->left, res);

        // Visit current node
        res.push_back(root->data);

        // Traverse right subtree
        inorderHelper(root->right, res);
    }

    vector<int> inOrder(Node* root) {
        vector<int> res;
        inorderHelper(root, res);
        return res;
    }
};
