class Solution {
public:
    int maxSum;

    int findMaxSum(Node* root) {
        maxSum = INT_MIN;
        maxPathDown(root);
        return maxSum;
    }

private:
    int maxPathDown(Node* node) {
        if (!node) return 0;

        int left = max(0, maxPathDown(node->left));
        int right = max(0, maxPathDown(node->right));

        maxSum = max(maxSum, left + right + node->data);

        return max(left, right) + node->data;
    }
};
