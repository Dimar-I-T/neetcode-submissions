class Solution {
public:
    void removeChars(string& str, char c) {
        str.erase(remove(str.begin(), str.end(), c), str.end());
    }

    void getDirs(vector<string>& dirs, string path) {
        stringstream ss(path);
        string token;
        while (getline(ss, token, '/')) {
            dirs.push_back(token);
        }
    }

    string simplifyPath(string path) {
        int n = path.length();
        for (int x = 1; x < n; x++) {
            char prev = path[x - 1];
            char& curr = path[x];
            if (prev == '/' && curr == '/') {
                curr = ' ';
            }
        }

        removeChars(path, ' ');
        vector<string> dirs;
        getDirs(dirs, path);

        stack<string> st;
        for (string s : dirs) {
            if (s == "") {
                continue;
            }

            if (s == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            } else if (s == ".") {
                continue;
            } else {
                st.push(s);
            }
        }

        vector<string> resV;
        resV.reserve(st.size());
        while (!st.empty()) {
            resV.emplace_back(st.top());
            st.pop();
        }

        reverse(resV.begin(), resV.end());
        string res = "/";
        for (string s : resV) {
            res += s;
            res += "/";
        }

        if (res.length() > 1) {
            res = res.substr(0, res.length() - 1);
        }

        return res;
    }
};