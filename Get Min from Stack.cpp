#include <stack>
using namespace std;

class Solution {
    stack<int> mainStack;
    stack<int> minStack;

public:
    // Constructor
    Solution() {}

    // Push element onto stack
    void push(int x) {
        mainStack.push(x);
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        } else {
            minStack.push(minStack.top());
        }
    }

    // Remove top element from stack
    void pop() {
        if (!mainStack.empty()) {
            mainStack.pop();
            minStack.pop();
        }
    }

    // Return top element of stack
    int peek() {
        if (mainStack.empty()) return -1;
        return mainStack.top();
    }

    // Return minimum element in stack
    int getMin() {
        if (minStack.empty()) return -1;
        return minStack.top();
    }
};
