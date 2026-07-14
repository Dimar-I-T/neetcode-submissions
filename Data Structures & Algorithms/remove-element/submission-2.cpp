class Solution {
public:
    static bool cmp(int a, int b) {
        return (a < 0 && b >= 0);
    }

    int removeElement(vector<int>& nums, int val) {
        int kCom = 0;
        for (int x = 0; x < nums.size(); x++) {
            if (nums[x] == val) {
                nums[x] = -1;
                kCom++;
            }
        }

        int k = nums.size() - kCom;
        if (k > 0) {
            sort(nums.rbegin(), nums.rend(), cmp);
        }

        return k;
    }
};