#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int getMaxArea(vector<int> arr) {
        int n = arr.size();
        stack<int> st;
        int maxArea = 0;
        int i = 0;

        while (i < n) {
            if (st.empty() || arr[st.top()] <= arr[i]) {
                st.push(i++);
            } else {
                int height = arr[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
        }

        while (!st.empty()) {
            int height = arr[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }

        return maxArea;
    }
};
