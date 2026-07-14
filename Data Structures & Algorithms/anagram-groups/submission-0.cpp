class Solution {
public:
    void removeWhiteSpaces(string &s) {
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
    }

    void sortString(string &s) {
        sort(s.begin(), s.end());
    }

    string sortAndRemove(string s) {
        removeWhiteSpaces(s);
        sortString(s);
        return s;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> um;
        um.reserve(strs.size());
        for (string s : strs) {
            string key = sortAndRemove(s); 
            um[key].push_back(s);
        }

        vector<vector<string>> res;
        for (auto itr = um.begin(); itr != um.end(); ++itr) {
            res.push_back(itr->second);
        }

        return res;
    }
};
