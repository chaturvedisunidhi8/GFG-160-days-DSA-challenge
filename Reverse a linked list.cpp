class Solution {
  public:
    Node* reverseList(struct Node* head) {
        // code here
        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;
        
        while (current != NULL) {
            next = current->next;  
            current->next = prev;   
            prev = current;        
            current = next;       
        }
        
        return prev;
    }
};
