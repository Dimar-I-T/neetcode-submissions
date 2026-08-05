class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 1;
        int n = nums.size();
        int next = nums[0];
        int k = 0;
        for (int x = 1; x < n; x++) {
            if (l >= n) {
                break;
            }

            if (nums[x - 1] != nums[x]) {
                next = nums[x];
                nums[l] = next;
                l++;
                k++;
            }
        }

        return k + 1;
    }
};