
class Solution {
public:
    int evaluate(vector<string>& arr) {
        stack<int> st;

        for (string& token : arr) {
            if (isOperator(token)) {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(applyOp(a, b, token));
            } else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }

private:
    bool isOperator(const string& s) {
        return s == "+" || s == "-" || s == "*" || s == "/";
    }

    int applyOp(int a, int b, const string& op) {
        if (op == "+") return a + b;
        if (op == "-") return a - b;
        if (op == "*") return a * b;
        if (op == "/") return a / b;
        return 0;
    }
};
