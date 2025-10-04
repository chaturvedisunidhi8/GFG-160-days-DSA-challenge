class Solution {
public:
    std::unordered_set<int> seen;

    bool findTarget(Node* root, int k) {
        if (!root) return false;

        if (seen.count(k - root->data)) return true;

        seen.insert(root->data);

        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};
