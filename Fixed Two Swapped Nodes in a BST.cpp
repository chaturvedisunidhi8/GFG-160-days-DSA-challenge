class Solution {
public:
    Node* first = NULL;
    Node* middle = NULL;
    Node* last = NULL;
    Node* prev = NULL;

    void correctBST(Node* root) {
        // Inorder traversal to find the two swapped nodes
        inorder(root);
        
        // Fix the swapped nodes
        if (first && last) {
            swap(first->data, last->data);
        } else if (first && middle) {
            swap(first->data, middle->data);
        }
    }

    void inorder(Node* root) {
        if (!root) return;

        inorder(root->left);

        if (prev && root->data < prev->data) {
            if (!first) {
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }

        prev = root;

        inorder(root->right);
    }
};
