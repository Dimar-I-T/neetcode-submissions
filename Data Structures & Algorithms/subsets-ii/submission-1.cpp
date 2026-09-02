class Solution {
public:
    void backtrack(int i, vector<int> sek, vector<int>& nums, vector<vector<int>>& hasil) {
        hasil.push_back(sek);
        for (int x = i; x < nums.size(); x++) {
            if (x > i && nums[x] == nums[x - 1]) {
                continue;
            }

            sek.push_back(nums[x]);
            backtrack(x + 1, sek, nums, hasil);
            sek.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> hasil;
        sort(nums.begin(), nums.end());
        backtrack(0, {}, nums, hasil);
        return hasil;
    }
};