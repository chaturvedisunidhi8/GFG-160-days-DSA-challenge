class Solution {
public:
    Node* cloneLinkedList(Node* head) {
        if (!head) return nullptr;
        
        // Step 1: Create interleaved list (A → A' → B → B')
        Node* current = head;
        while (current) {
            Node* copied = new Node(current->data);
            copied->next = current->next;
            current->next = copied;
            current = copied->next;
        }
        
        // Step 2: Assign random pointers
        current = head;
        while (current) {
            if (current->random) {
                current->next->random = current->random->next;
            }
            current = current->next->next;
        }
        
        // Step 3: Separate the two lists
        current = head;
        Node* newHead = head->next;
        Node* copyCurrent = newHead;
        
        while (current) {
            current->next = current->next->next;
            current = current->next;
            
            if (copyCurrent->next) {
                copyCurrent->next = copyCurrent->next->next;
                copyCurrent = copyCurrent->next;
            }
        }
        
        return newHead;
    }
};
