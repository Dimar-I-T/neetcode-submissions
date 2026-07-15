class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int limit = n / 3;
        unordered_map<int, int> freq;
        vector<int> res;
        res.reserve(n);
        freq.reserve(n);
        for (int x = 0; x < n; x++) {
            int &curr = nums[x];
            freq[curr]++;
            if (freq[curr] > limit) {
                freq[curr] = -INT_MIN;
                res.emplace_back(curr);
            }
        }

        return res;
    }
};