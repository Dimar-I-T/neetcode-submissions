class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        vector<int> ind(128);
        fill(ind.begin(), ind.end(), -1);
        int l = 0;
        ind[s[l]] = 0;
        int res = (n == 0) ? 0 : 1;
        for (int r = 1; r < n; r++){
            int c = s[r];
            if (l <= ind[c]) {
                l = ind[c] + 1;
            }

            ind[c] = r;
            res = max(res, r - l + 1);
        }

        return res;
    }
};
