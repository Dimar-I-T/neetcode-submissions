class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int res = -INT_MAX;
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int left = INT_MAX;
            int right = INT_MAX;
            if (mid > 0) {
                left = nums[mid - 1];
            }

            if (mid < n - 1) {
                right = nums[mid + 1];
            }

            int curr = nums[mid];
            // cek puncak
            if (curr > right && curr > left) {
                res = min(left, right);
                break;
            }

            // cek lembah
            if (curr < right && curr < left) {
                res = curr;
                break;
            }

            int mostLeft = nums[n - 1];
            if (curr > mostLeft) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }

            res = curr;
        }

        return res;
    }
};
