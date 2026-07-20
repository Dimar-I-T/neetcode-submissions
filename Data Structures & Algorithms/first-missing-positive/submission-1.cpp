class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int add = 1000000;
        for (int x = 0; x < n; x++) {
            int curr = nums[x];
            if (curr < 1 || (curr > n && curr <= add)) {
                nums[x] = 0;
                continue;
            }

            int idx = (curr > add) ? curr - add - 1: curr - 1;
            if (idx > n || idx < 0) {
                continue;
            }

            nums[idx] += add;
        }

        int res = 1;
        for (int x = 0; x < n; x++) {
            if (nums[x] < add) {
                break;
            }

            res++;
        }

        return res;
    }
};