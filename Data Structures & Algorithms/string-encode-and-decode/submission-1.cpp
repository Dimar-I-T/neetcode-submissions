class Solution {
   public:
    vector<string> split(string s, const string& delimiter) {
        vector<string> tokens;
        size_t pos = 0;
        string token;
        while ((pos = s.find(delimiter)) != string::npos) {
            token = s.substr(0, pos);
            tokens.push_back(token);
            s.erase(0, pos + delimiter.length());
        }

        tokens.push_back(s);
        return tokens;
    }

    string bridge =
        "!*@&^#&^@*&#^&*@^#*!@^#*&^!@*#&!@#*!@&#*@!#^!@%#*!^@*#^*!&@#^*&!@^#*&!#@^*&^!@#&*^!@&*#^*!"
        "@&#^*&!@#^*!&@#^*&!@#^*!&@^#*&^!@*#&%!@#!@&*#%*!@#%*!@#";

    string null_val = "@)#*$)@#*$)*@#$#*$&@(&$*!&)$(#*)($@*)($&@)#&$)@#*($)(#@*)$&(#@*^$(*#@%^9#@&$#@))";

    string encode(vector<string>& strs) {
        if (strs.size() == 0) {
            return null_val;
        }

        string encoded_string = "";
        for (int x = 0; x < strs.size() - 1; x++) {
            encoded_string += strs[x] + bridge;
        }
        
        encoded_string += strs[strs.size() - 1];
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_strs = split(s, bridge);
        auto ne = remove(decoded_strs.begin(), decoded_strs.end(), null_val);
        decoded_strs.erase(ne, decoded_strs.end());
        return decoded_strs;
    }
};
