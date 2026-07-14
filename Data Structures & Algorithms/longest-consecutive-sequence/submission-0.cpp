class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        s.reserve(n);
        for (int x : nums) {
            s.insert(x);
        }

        int res = 0;
        for (int x : nums) {
            if (s.count(x) == 0) {
                continue;
            }

            int f = 0;
            int curr = x;
            while (s.count(curr) != 0) {
                f++;
                s.erase(curr);
                curr++;
            }

            curr = x - 1;
            while (s.count(curr) != 0) {
                f++;
                s.erase(curr);
                curr--;
            }

            res = max(res, f);
        }

        return res;
    }
};
