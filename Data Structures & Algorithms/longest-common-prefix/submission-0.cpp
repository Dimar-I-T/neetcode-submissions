class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        int k = 0;
        bool complete = 1;
        while (k < strs[0].size()) {
            bool sama = 1;
            char cFirst = strs[0][k];
            for (string s : strs) {
                auto itr = s.begin() + k;
                if (itr == s.end() || cFirst != *itr) {
                    complete = 0;
                    break;
                }
            }
            
            if (!complete) {
                break;
            }

            res += cFirst;
            k++;
        }

        return res;
    }
};