class Solution {
public:
    void backtrack(int i, int sisa, vector<int> sek, vector<int>& arr, vector<vector<int>>& hasil) {
        if (sisa < 0) {
            return;
        }

        if (sisa == 0) {
            hasil.push_back(sek);
            return;
        }

        for (int x = i; x < arr.size(); x++) {
            if (x > i && arr[x] == arr[x - 1]) {
                continue;
            }

            sek.push_back(arr[x]);
            backtrack(x + 1, sisa - arr[x], sek, arr, hasil);
            sek.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> hasil;
        sort(candidates.begin(), candidates.end());
        backtrack(0, target, {}, candidates, hasil);
        return hasil;
    }
};
