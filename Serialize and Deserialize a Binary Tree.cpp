class Solution {
public:
    // Function to serialize a tree and return a list containing nodes of tree
    vector<int> serialize(Node *root) {
        vector<int> result;
        if (!root) return result;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* node = q.front();
            q.pop();

            if (node == nullptr) {
                result.push_back(-1); // Null marker
            } else {
                result.push_back(node->data);
                q.push(node->left);
                q.push(node->right);
            }
        }

        return result;
    }

    // Function to deserialize a list and construct the tree
    Node* deSerialize(vector<int> &arr) {
        if (arr.empty() || arr[0] == -1) return nullptr;

        Node* root = new Node(arr[0]);
        queue<Node*> q;
        q.push(root);

        int i = 1;
        while (!q.empty() && i < arr.size()) {
            Node* current = q.front();
            q.pop();

            // Left child
            if (arr[i] != -1) {
                current->left = new Node(arr[i]);
                q.push(current->left);
            }
            i++;

            // Right child
            if (i < arr.size() && arr[i] != -1) {
                current->right = new Node(arr[i]);
                q.push(current->right);
            }
            i++;
        }

        return root;
    }
};
