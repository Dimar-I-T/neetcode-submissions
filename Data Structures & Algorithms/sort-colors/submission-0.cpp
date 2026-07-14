class Solution {
public:
    void sortColors(vector<int>& nums) {
        int array[3] = {0};
        for (int n : nums) {
            array[n]++;
        }       

        int n = nums.size();
        int k = 0;
        for (int x = 0; x < n; x++) {
            while (array[k] == 0) {
                k++;
            }

            nums[x] = k;
            array[k]--;
        }
    }
};