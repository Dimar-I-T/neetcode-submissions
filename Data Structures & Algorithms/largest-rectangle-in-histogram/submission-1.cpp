class Solution {
public:
    struct Container {
        int idx = 0;
        int val = 0;
        int prevSmallerIdx = 0;
        int nextSmallerIdx = 0;
    };

    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(-INT_MAX);
        int n = heights.size();
        vector<Container> containers(n);

        // step 1: fill containers
        for (int x = 0; x < n; x++) {
            int currVal = heights[x];
            int idx1 = x;
            containers[x].idx = idx1;
            containers[x].val = currVal;
        }

        // step 2: iterate
        stack<Container> st;
        st.push({-1, -INT_MAX, 0, 0});
        for (int x = 0; x < n; x++) {
            Container prev = st.top();
            int prevVal = prev.val;
            int prevIdx = prev.idx;

            int currVal = heights[x];
            int currIdx = x;
            if (prevVal >= currVal) {
                // go to the left as we pop the stack
                while (!st.empty()) {
                    // step 3: finding prev smaller
                    // step 4: finding next smaller
                    prev = st.top();
                    int leftVal = prev.val;
                    int leftIdx = prev.idx;
                    if (leftIdx >= 0) {
                        if (containers[leftIdx].prevSmallerIdx == 0){
                            containers[leftIdx].prevSmallerIdx = 1;
                        }

                        if (leftVal > currVal) {
                            containers[leftIdx].nextSmallerIdx = currIdx - leftIdx;
                        }
                    }

                    if (leftVal < currVal) {
                        containers[currIdx].prevSmallerIdx = currIdx - leftIdx;
                        break;
                    }

                    st.pop();
                }
            }

            st.push({currIdx, currVal, 0, 0});
        }

        // step 5
        int res = 0;
        for (int x = 0; x < n - 1; x++) {
            int currVal = containers[x].val;
            int prevIdx = containers[x].prevSmallerIdx;
            int nextIdx = containers[x].nextSmallerIdx;
            int area = currVal * (prevIdx + nextIdx - 1);
            res = max(res, area);
        }

        return res;
    }
};
