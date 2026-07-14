class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        for (int x = 0; x < n; x++) {
            nums.push_back(nums[x]);
        }

        return nums;
    }
};