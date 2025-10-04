
// Custom comparator for min-heap
struct compare {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

class Solution {
public:
    // Function to merge k sorted linked lists.
    Node* mergeKLists(vector<Node*> &lists) {
        priority_queue<Node*, vector<Node*>, compare> minHeap;

        // Push the head of each list into the min-heap
        for (auto node : lists) {
            if (node != NULL)
                minHeap.push(node);
        }

        Node* dummy = new Node(0);
        Node* tail = dummy;

        while (!minHeap.empty()) {
            Node* top = minHeap.top();
            minHeap.pop();

            tail->next = top;
            tail = tail->next;

            if (top->next != NULL)
                minHeap.push(top->next);
        }

        return dummy->next;
    }
};
