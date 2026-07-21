class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        st.push('0');
        unordered_map<char, char> openClose = {{'[', ']'}, {'(', ')'}, {'{', '}'}};
        bool res = 1;
        for (char c : s) {
            if (openClose.contains(c)) {
                st.push(c);
            } else {
                char open = st.top();
                if (openClose[open] == c) {
                    st.pop();
                } else {
                    res = 0;
                    break;
                }
            }
        }

        return (res && st.size() == 1);
    }
};
