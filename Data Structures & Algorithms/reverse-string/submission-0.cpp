class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for (int x = 0; x < n / 2; x++) {
            char temp = s[x];
            s[x] = s[n - x - 1];
            s[n - x - 1] = temp;
        }
    }
};