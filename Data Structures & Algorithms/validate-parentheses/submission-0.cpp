class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> cc;
        cc[')'] = '(';
        cc[']'] = '[';
        cc['}'] = '{';
        vector<char> stack;
        bool bisa = 1;
        for (int x = 0; x < s.length(); x++){
            if (s[x] == '(' || s[x] == '{' || s[x] == '['){
                stack.push_back(s[x]);
            }else{
                if (stack.empty()){
                    bisa = 0;
                    break;
                }
                
                char c = stack[stack.size() - 1];
                if (cc[s[x]] != c){
                    bisa = 0;
                    break;
                }

                stack.pop_back();
            }
        }
        
        if (!stack.empty()){
            bisa = 0;
        }

        return bisa;
    }
};