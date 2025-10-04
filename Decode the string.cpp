class Solution {
public:
    string decodedString(string s) {
        stack<string> strStack;
        stack<int> countStack;
        string curr = "";
        int k = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                k = k * 10 + (ch - '0');
            }
            else if (ch == '[') {
                countStack.push(k);
                strStack.push(curr);
                curr = "";
                k = 0;
            }
            else if (ch == ']') {
                string temp = curr;
                curr = strStack.top();
                strStack.pop();
                int repeat = countStack.top();
                countStack.pop();
                while (repeat--) {
                    curr += temp;
                }
            }
            else {
                curr += ch;
            }
        }

        return curr;
    }
};
