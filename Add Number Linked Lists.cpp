class Solution {
public:
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        while (curr != NULL) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    Node* addTwoLists(Node* num1, Node* num2) {
        // Step 1: Reverse both lists
        num1 = reverse(num1);
        num2 = reverse(num2);

        Node* dummy = new Node(0);
        Node* temp = dummy;
        int carry = 0;

        // Step 2: Add digits
        while (num1 != NULL || num2 != NULL || carry) {
            int sum = carry;
            if (num1) {
                sum += num1->data;
                num1 = num1->next;
            }
            if (num2) {
                sum += num2->data;
                num2 = num2->next;
            }
            carry = sum / 10;
            temp->next = new Node(sum % 10);
            temp = temp->next;
        }

        // Step 3: Reverse the result
        Node* result = reverse(dummy->next);

        // Step 4: Remove leading zeroes
        while (result && result->data == 0 && result->next != NULL) {
            Node* toDelete = result;
            result = result->next;
            delete toDelete;
        }

        return result;
    }
};
