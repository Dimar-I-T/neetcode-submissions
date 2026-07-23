class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int, int>> st;
        vector<int> answers(n);

        int prev = temperatures[0];
        st.push({prev, 0});
        for (int x = 1; x < n; x++) {
            int curr = temperatures[x];
            // cout << "prev: " << prev << "\n";
            // cout << "curr: " << curr << "\n";
            // cout << "x: " << x << "\n";
            if (curr > prev) {
                // cout << "Ke Kiri!\n";
                while (!st.empty()) {
                    pair<int, int> currLeft = st.top();
                    int currLeftVal = currLeft.first;
                    int currLeftInd = currLeft.second;
                    // cout << "val: " << currLeftVal << "\n";
                    // cout << "ind: " << currLeftInd << "\n";
                    if (curr <= currLeftVal) {
                        // cout << "BERHENTI!\n" << "\n"; 
                        break;
                    }

                    // cout << "hasil: " << x - currLeftInd << "\n";
                    answers[currLeftInd] = x - currLeftInd;
                    st.pop();
                }
            }

            // cout << "\n";
            prev = curr;
            st.push({curr, x});
        }

        return answers;
    }
};
