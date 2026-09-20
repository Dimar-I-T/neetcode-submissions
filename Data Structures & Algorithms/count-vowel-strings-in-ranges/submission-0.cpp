class Solution {
   public:
    vector<int> arr;
    unordered_map<char, bool> isVowel;

    void isiVowel() {
        vector<char> vowels = {'a', 'i', 'u', 'e', 'o'};
        for (char c : vowels) {
            isVowel[c] = 1;
        }
    }

    bool startsEndsVowel(string s) {
        return isVowel[s[0]] && isVowel[s[s.length() - 1]];
    }

    void isiArr(vector<string>& words) {
        int n = words.size();
        for (int x = 0; x < n; x++) {
            if (startsEndsVowel(words[x])) {
                arr[x] = 1;
            }
        }
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        isiVowel();
        int n = words.size();
        arr.clear(); arr.resize(n, 0);
        isiArr(words);

        // jadiin prefSum
        for (int x = 1; x < n; x++) {
            arr[x] += arr[x - 1];
        }

        int q = queries.size();
        vector<int> res(q);
        for (int x = 0; x < q; x++) {
            int l = queries[x][0], r = queries[x][1];
            int kiri = 0;
            if (l > 0) {
                kiri = arr[l - 1];
            }
            
            res[x] = arr[r] - kiri;
        }

        return res;
    }
};