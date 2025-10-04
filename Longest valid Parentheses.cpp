
class Solution {
public:
    static int maxLength(string s) {
        int maxLen = 0;
        stack<int> st;
        st.push(-1); 

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i); 
                } else {
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }

        return maxLen;
    }
};


