class Solution {
public:
    int appendCharacters(string s, string t) {
        int ns = s.length();
        int nt = t.length();
        int i = 0, j = 0;
        int ctr = 0;
        while (i < ns && j < nt) {
            if (s[i] == t[j]) {
                ctr++;
                j++;
            }

            i++;
        }

        return nt - ctr;
    }
};