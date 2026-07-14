class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        long long product = 1;
        int nZero = 0;
        int idxZero = 0;
        for (int x = 0; x < n; x++) {
            if (nums[x] == 0) {
                idxZero = x;
                nZero++;
            }
        }

        if (nZero <= 1) {
            for (int x : nums) {
                if (x == 0) {
                    continue;
                }

                product *= x;
            }

            if (nZero == 1) {
                res[idxZero] = product;
            } else {
                for (int x = 0; x < n; x++) {
                    res[x] = product / nums[x];
                }
            }
        }

        return res;
    }
};
