class Solution {
public:
    string whiteSpace(int n) {
        string res = "";
        for (int x = 0; x < n; x++) {
            res += " ";
        }

        return res;
    }

    void isiRes(vector<string>& s, int m, vector<string>& res) {
        int n = s.size();
        if (n == 1) {
            res.push_back(s[0] + whiteSpace(m - s[0].length()));
            return;
        }

        int sisaLine = m - (s[0].length() + s[n - 1].length());
        int ns = n - 2;
        int sumSisa = 0;
        for (int x = 1; x < n - 1; x++) {
            sumSisa += s[x].length();
        }

        int sisaSpace = sisaLine - sumSisa;
        int banyakSpace = ns + 1;
        int a = banyakSpace, b = 0;
        double x = (double)((double)sisaSpace / (double)banyakSpace);
        int ceilx = 0; 
        int flx = x;
        string tengah = "";
        if (sisaSpace % banyakSpace != 0) {
            flx = sisaSpace / banyakSpace;
            ceilx = flx + 1;
            a = -sisaSpace + ceilx * banyakSpace;
            b = sisaSpace - flx * banyakSpace;
        }

        // b dulu
        // a setelahnya
        int i = 1;
        while (b > 0) {
            tengah += whiteSpace(ceilx);
            tengah += s[i];
            b--;
            i++;
        }

        while (a > 0) {
            if (i < n - 1) {
                tengah += whiteSpace(flx);
                tengah += s[i];
            }

            a--;
            i++;
        }

        tengah += whiteSpace(flx);
        string line = s[0] + tengah + s[n - 1];
        res.push_back(line);
    }
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = words.size();
        vector<string> temp;
        int sTemp = 0;
        for (int x = 0; x < n; x++) {
            string curr = words[x];
            int len = curr.length();
            if (sTemp + len + temp.size() > maxWidth) {
                isiRes(temp, maxWidth, res);
                temp.clear();
                sTemp = 0;
            }

            sTemp += len;
            temp.push_back(curr);
        }

        if (!temp.empty()) {
            string left = "";
            for (string t : temp) {
                left += t + " ";
            }

            left = left.substr(0, left.length() - 1);
            res.push_back(left + whiteSpace(maxWidth - left.length()));
        }

        return res;
    }
};