class Solution {
public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        if (!root) return nullptr;

        if (n1->data < root->data && n2->data < root->data)
            return LCA(root->left, n1, n2);

        if (n1->data > root->data && n2->data > root->data)
            return LCA(root->right, n1, n2);

        return root;
    }
};
