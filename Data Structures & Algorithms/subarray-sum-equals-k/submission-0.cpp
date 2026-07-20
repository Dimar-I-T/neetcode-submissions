class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // prefix
        // [1, 2, 3, 2, 4], k = 6
        // [1, 3, 6, 8, 12], k = 6
        // unordered_map<int, int> freq
        // l r -> nums[r] - nums[l - 1] = k
        // (nums[r] - k) = nums[l - 1]
        // 

        int n = nums.size();
        unordered_map<int, int> freq;
        freq.reserve(n);
        for (int x = 1; x < n; x++) {
            nums[x] += nums[x - 1];
        }

        freq[0] = 1;
        int res = 0;
        for (int x = 0; x < n; x++) {
            int curr = nums[x];
            int fr = 0;
            auto itr = freq.find(curr - k);
            if (itr != freq.end()) {
                fr = itr->second;
            }

            if (fr >= 1) {
                res += fr;
            }

            freq[curr]++;
        }

        return res;
    }
};