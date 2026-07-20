class Solution {
   public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        for (string str : operations) {
            if (str == "+") {
                int fi = s.top();
                s.pop();
                int se = s.top();
                s.pop();
                int la = fi + se;
                s.push(se);
                s.push(fi);
                s.push(la);
            } else if (str == "D") {
                int la = 2 * s.top();
                s.push(la);
            } else if (str == "C") {
                s.pop();
            } else {
                int la = stoi(str);
                s.push(la);
            }
        }

        int sum = 0;
        while (!s.empty()) {
            int curr = s.top();
            sum += curr;
            s.pop();
        }

        return sum;
    }
};