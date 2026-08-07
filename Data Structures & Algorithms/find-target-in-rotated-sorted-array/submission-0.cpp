class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        int res = INT_MAX;
        int mostLeft = nums[n - 1];
        while (l <= r) {
            int mid = (l + r) / 2;
            int curr = nums[mid];
            if (curr == target) {
                return mid;
            }

            // l to mid
            bool bLeft1 = (curr <= target) && (curr <= mostLeft) && (target <= mostLeft);
            bool bLeft2 = (target <= mostLeft) && (target <= curr) && (mostLeft <= curr);
            bool bLeft3 = (mostLeft <= curr) && (mostLeft <= target) && (curr < target);
            if (bLeft1 || bLeft2 || bLeft3) {
                l = mid + 1;
                continue;
            }

            // r to mid
            bool bRight1 = (target <= curr) && (target <= mostLeft) && (curr <= mostLeft);
            bool bRight2 = (curr <= mostLeft) && (curr <= target) && (mostLeft <= target);
            bool bRight3 = (mostLeft <= target) && (mostLeft <= curr) && (target <= curr);
            if (bRight1 || bRight2 || bRight3) {
                r = mid - 1;
                continue;
            }
        }

        return -1;
    }
};
