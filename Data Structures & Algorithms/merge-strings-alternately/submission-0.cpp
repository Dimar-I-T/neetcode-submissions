class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.length(), n2 = word2.length();
        int i1 = 0, i2 = 0;

        int k = 0;
        string res = "";
        while (i1 < n1 || i2 < n2) {
            if (i1 < n1 && k % 2 == 0) {
                res += word1[i1];
                i1++;
            }

            if (i2 < n2 && k % 2 == 1) {
                res += word2[i2];
                i2++;
            }

            k++;
        }

        return res;
    }
};