class Solution {
public:
    bool isPalindrome(string s) {
        string s1;
        for (auto c : s) {
            char c1 = tolower(c);
            if ((c1 >= 97 && c1 <= 122) || (c >= 48 && c <= 57)) {
                s1 += c1;
            }
        }

        int l = 0, r = s1.length() - 1;
        bool bisa = 1;
        while (l < r) {
            if (s1[l] != s1[r]) {
                bisa = 0;
                break;
            }

            l++;
            r--;
        }

        return bisa;
    }
};