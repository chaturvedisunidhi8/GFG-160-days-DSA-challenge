class Solution {
public:
    Node *reverseKGroup(Node *head, int k) {
        if (!head) return NULL;

        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        int count = 0;

        // First, check if there are at least k nodes to reverse
        Node* temp = head;
        int nodesCount = 0;
        while (temp && nodesCount < k) {
            temp = temp->next;
            nodesCount++;
        }

        // If less than k nodes, reverse them as a group as per GFG instructions
        if (nodesCount < k) {
            // Reverse the remaining nodes
            curr = head;
            while (curr != NULL) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            return prev;
        }

        // Step 1: Reverse first k nodes
        while (curr != NULL && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // Step 2: Recursively call for the rest of the list
        if (next != NULL) {
            head->next = reverseKGroup(next, k);
        }

        // prev is new head of this segment
        return prev;
    }
};
