class Solution {
public:
    Node* findFirstNode(Node* head) {
        if (!head || !head->next) return nullptr;
        
        Node* slow = head;
        Node* fast = head;
        
        // Step 1: Detect if there's a cycle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) break;  // Cycle detected
        }
        
        // No cycle found
        if (slow != fast) return nullptr;
        
        // Step 2: Find the cycle's starting node
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
};

