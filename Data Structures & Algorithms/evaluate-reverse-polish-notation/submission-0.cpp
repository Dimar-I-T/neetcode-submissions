class Solution {
public:
    int operate(int a, int b, string op) {
        int res = 0;
        if (op == "+") {
            res = a + b;
        } else if (op == "-") {
            res = a - b;
        } else if (op == "*") {
            res = a * b;
        } else if (op == "/" && b != 0) {
            res = a / b;
        }

        return res;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string token : tokens) {
            if (token == "+" || token == "*" || token == "-" || token == "/") {
                int se = st.top();
                st.pop();
                int fi = st.top();
                st.pop();
                int res = operate(fi, se, token);
                st.push(res);
            } else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};
