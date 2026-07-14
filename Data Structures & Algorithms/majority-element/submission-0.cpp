class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> um;
        int n = nums.size();
        um.reserve(n);
        for (int x : nums) {
            um[x]++;
        }

        pair<int, int> max = *(um.begin());
        for (auto &i : um) {
            if (max.second < i.second) {
                max = i;
            }
        }

        return max.first;
    }
};