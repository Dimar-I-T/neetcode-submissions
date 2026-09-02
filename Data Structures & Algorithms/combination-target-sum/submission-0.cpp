class Solution {
public:
    void backtrack(int i, int sisa, vector<int> sek, vector<int>& nums, vector<vector<int>>& hasil) {
        if (sisa < 0) {
            return;
        }

        if (sisa == 0) {
            hasil.push_back(sek);
            return;
        }

        for (int x = i; x < nums.size(); x++) {
            if (x > i && nums[x - 1] == nums[x]) {
                continue;
            }

            sek.push_back(nums[x]);
            backtrack(x, sisa - nums[x], sek, nums, hasil);
            sek.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> hasil;
        sort(nums.begin(), nums.end());
        backtrack(0, target, {}, nums, hasil);
        return hasil;
    }
};
