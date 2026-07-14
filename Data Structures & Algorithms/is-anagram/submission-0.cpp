class Solution {
public:
    void removeWhiteSpace(string &str) {
        str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    }

    int valMap(unordered_map<char, int> &um, char key) {
        auto itr = um.find(key);
        if (itr != um.end()) {
            return itr->second;
        } else {
            return -1;
        }
    }

    bool isAnagram(string s, string t) {
        unordered_map<char, int> sm, tm;
        removeWhiteSpace(s);
        removeWhiteSpace(t);
        sm.reserve(s.length());
        tm.reserve(t.length());
        if (s.length() != t.length()) {
            return 0;
        }

        for (char c : s) {
            sm[c]++;
        }

        for (char c : t) {
            tm[c]++;
        }

        bool sama = 1;
        for (char c : t) {
            if (valMap(sm, c) != valMap(tm, c)) {
                sama = 0;
                break;
            }
        }

        return sama;
    }
};