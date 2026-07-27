class Solution {
public:
    struct RepString {
        int rep;
        string strr;
    };

    bool isNumber(char c) {
        return (c >= 48 && c <= 57);
    }

    string repeat(string s, int k) {
        string res = "";
        while (k-- > 0) {
            res += s;
        }

        return res;
    }

    string decodeString(string s) {
        stack<RepString> st;
        st.push({1, ""});
        RepString currTop = st.top();
        string numS = "";
        for (char c : s) {
            if (isNumber(c)) {
                numS += c;
            } else {
                if (c == '[') {
                    int repInt = stoi(numS);
                    numS = "";
                    st.push({currTop.rep, currTop.strr});
                    currTop = {repInt, ""};
                } else if (c == ']') {
                    string newStr = repeat(currTop.strr, currTop.rep);
                    RepString prev = st.top();
                    st.pop();
                    currTop = {prev.rep, prev.strr + newStr};
                } else {
                    currTop.strr += c;
                }
            }
        }

        return currTop.strr;
    }
};