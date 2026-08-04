class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.length();
        int notSame = 0;
        int l = 0;
        int r = n - 1;
        while (l < r) {
            if (notSame > 1) {
                break;
            }

            if (s[l] != s[r]) {
                notSame++;
                l++;
                continue;
            }

            l++;
            r--;
        }

        if (notSame == 0) {
            return 1;
        }

        int notSame1 = 0;
        l = 0;
        r = n - 1;
        while (l < r) {
            if (notSame1 > 1) {
                break;
            }

            if (s[l] != s[r]) {
                notSame1++;
                r--;
                continue;
            }

            l++;
            r--;
        }

        int notS = min(notSame, notSame1);
        if (notS <= 1) {
            return 1;
        } else {
            return 0;
        }
    }
};