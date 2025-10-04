class Solution {
public:
    vector<int> boundaryTraversal(Node* root) {
        vector<int> result;
        if (root == NULL) return result;

        if (!isLeaf(root)) result.push_back(root->data);

        addLeftBoundary(root->left, result);
        addLeaves(root, result);
        addRightBoundary(root->right, result);

        return result;
    }

private:
    bool isLeaf(Node* node) {
        return (node->left == NULL && node->right == NULL);
    }

    void addLeftBoundary(Node* node, vector<int>& res) {
        while (node) {
            if (!isLeaf(node)) res.push_back(node->data);
            if (node->left) node = node->left;
            else node = node->right;
        }
    }

    void addRightBoundary(Node* node, vector<int>& res) {
        stack<int> temp;
        while (node) {
            if (!isLeaf(node)) temp.push(node->data);
            if (node->right) node = node->right;
            else node = node->left;
        }
        while (!temp.empty()) {
            res.push_back(temp.top());
            temp.pop();
        }
    }

    void addLeaves(Node* node, vector<int>& res) {
        if (isLeaf(node)) {
            res.push_back(node->data);
            return;
        }
        if (node->left) addLeaves(node->left, res);
        if (node->right) addLeaves(node->right, res);
    }
};
