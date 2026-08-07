class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int currMin = prices[0];
        int res = 0;
        for (int x = 1; x < n; x++) {
            int currVal = prices[x];
            if (currMin > currVal) {
                currMin = currVal;
                continue;
            }

            res = max(res, currVal - currMin);
        }

        return res;
    }
};
