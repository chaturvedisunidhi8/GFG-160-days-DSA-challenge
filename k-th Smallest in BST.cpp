class Solution {
public:
    int count = 0;
    int result = -1;

    void inorder(Node* root, int k) {
        if (!root) return;

        inorder(root->left, k);

        count++;
        if (count == k) {
            result = root->data;
            return;
        }

        inorder(root->right, k);
    }

    int kthSmallest(Node* root, int k) {
        inorder(root, k);
        return result;
    }
};
