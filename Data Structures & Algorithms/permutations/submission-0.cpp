class Solution {
public:
    void backtrack(vector<int> sek, vector<int>& nums, vector<vector<int>>& hasil, vector<bool> visited) {
        int n = nums.size();
        if (sek.size() == n) {
            hasil.push_back(sek);
            return;
        }

        for (int x = 0; x < n; x++) {
            if (visited[x]) {
                continue;
            }

            visited[x] = 1;
            sek.push_back(nums[x]);
            backtrack(sek, nums, hasil, visited);
            visited[x] = 0;
            sek.pop_back();
        }
    }


    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> hasil;
        backtrack({}, nums, hasil, vector<bool>(nums.size()));
        return hasil;
    }
};
