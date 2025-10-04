class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            vector<int> currentLevel;
            
            for (int i = 0; i < size; ++i) {
                Node* current = q.front();
                q.pop();
                currentLevel.push_back(current->data);
                
                if (current->left != nullptr)
                    q.push(current->left);
                if (current->right != nullptr)
                    q.push(current->right);
            }
            result.push_back(currentLevel);
        }
        
        return result;
    }
};
