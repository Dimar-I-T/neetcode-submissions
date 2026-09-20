class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        int prev = customers[0][0];
        vector<double> waits(n);
        for (int x = 0; x < n; x++) {
            int arrival = customers[x][0];
            int time = customers[x][1];
            if (prev < arrival) {
                prev = arrival;
            }

            int next = prev + time;
            waits[x] = next - arrival;
            prev = next;
        }

        double res = 0;
        for (double w : waits) {
            res += w;
        }

        return res/n;
    }
};