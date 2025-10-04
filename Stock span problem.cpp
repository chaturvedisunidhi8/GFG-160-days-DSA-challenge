class Solution {
public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        vector<int> span(n);  // To store result spans
        stack<int> s;  // Stack to store indices

        for (int i = 0; i < n; ++i) {
            // Pop elements from stack while stack is not empty and the top element is less than or equal to current
            while (!s.empty() && arr[s.top()] <= arr[i]) {
                s.pop();
            }

            // If stack becomes empty, it means there is no previous greater element
            span[i] = (s.empty()) ? (i + 1) : (i - s.top());

            // Push this element to stack
            s.push(i);
        }

        return span;
    }
};
