class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int res = 0;
        for (int x = 0; x < n; x++) {
            int left = (x == 0) ? INT_MAX : prices[x - 1];
            int right = (x == n - 1) ? -INT_MAX : prices[x + 1];
            int curr = prices[x];
            // lembah
            if (curr <= left && curr < right) {
                res -= curr;
            }

            // bukit
            if (curr > left && curr >= right) {
                res += curr;
            }
        }

        return res;
    }
};