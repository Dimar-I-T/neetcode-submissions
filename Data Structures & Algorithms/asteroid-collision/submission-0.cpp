class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        st.push(asteroids[0]);
        for (int x = 1; x < n; x++) {
            int curr = asteroids[x];
            int prev = (!st.empty()) ? st.top() : 0;
            if ((prev >= 0) && curr < 0) {
                bool stop = 0;
                int currSize = abs(curr);
                while (!st.empty() && !stop) {
                    int left = st.top();
                    if (left < 0) {
                        break;
                    }

                    if (left < currSize) {
                        st.pop();
                    } else if (left == currSize) {
                        st.pop();
                        stop = 1;
                        break;
                    } else {
                        stop = 1;
                        break;
                    }
                }

                if (!stop) {
                    st.push(curr);
                }
            } else {
                st.push(curr);
            }
        } 

        vector<int> res;
        res.reserve(st.size());
        while (!st.empty()) {
            res.emplace_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};