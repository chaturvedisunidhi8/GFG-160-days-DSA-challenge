class Solution {
public:
    void countPaths(Node* node, int k, vector<int>& path, int &count) {
        if (!node) return;

        // Add current node to the path
        path.push_back(node->data);

        // Check path sums ending at this node
        int sum = 0;
        for (int i = path.size() - 1; i >= 0; i--) {
            sum += path[i];
            if (sum == k)
                count++;
        }

        // Recursive calls to left and right subtree
        countPaths(node->left, k, path, count);
        countPaths(node->right, k, path, count);

        // Backtrack
        path.pop_back();
    }

    int sumK(Node *root, int k) {
        vector<int> path;
        int count = 0;
        countPaths(root, k, path, count);
        return count;
    }
};
