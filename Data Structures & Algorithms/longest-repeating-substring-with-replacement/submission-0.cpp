class Solution {
public:
    struct Maks {
        char c;
        int freq;
    };

    int characterReplacement(string s, int k) {
        int n = s.length();
        unordered_map<char, int> freq;
        int l = 0, r = 1;
        freq[s[l]]++;
        Maks maks = {s[l], freq[s[l]]};
        int res = 1;
        while (r < n) {
            freq[s[r]]++;
            if (freq[s[r]] > maks.freq) {
                maks = {s[r], freq[s[r]]};
            }

            if (r - l + 1 - maks.freq > k) {
                freq[s[l]]--;
                if (s[l] == maks.c) {
                    maks.freq--;
                }

                l++;
            } else {
                res = max(res, r - l + 1);
            }   

            r++;
        }    

        return res;
    }
};
