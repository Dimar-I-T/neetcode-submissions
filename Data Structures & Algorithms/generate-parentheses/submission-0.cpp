class Solution {
public:
    int N;

    string selipkan(string s, int i, string& ke) {
        string kiri = ke.substr(0, i);
        string kanan = ke.substr(i, ke.size() - i);
        string res = kiri + s + kanan;
        return res;
    }

    void go(int i, string sek, vector<string>& hasil, unordered_map<string, bool>& sudah) {
        if (sudah[sek]) {
            return;
        }

        sudah[sek] = 1;
        if (i == N) {
            hasil.push_back(sek);
            return;
        }

        int n = sek.length();
        for (int x = 0; x < n; x++) {
            string sel = sek;
            sel = selipkan("()", x, sel);
            go(i + 1, sel, hasil, sudah);
        }
    }

    vector<string> generateParenthesis(int n) {
        N = n;
        vector<string> hasil;
        unordered_map<string, bool> sudah;
        go(1, "()", hasil, sudah);
        return hasil;
    }
};