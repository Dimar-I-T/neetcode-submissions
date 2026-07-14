class Solution {
public:
    static bool comp(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        um.reserve(nums.size());
        for (int x : nums) {
            um[x]++;
        }

        vector<pair<int, int>> v;
        for (auto &itr : um) {
            v.push_back(itr);
        }

        sort(v.begin(), v.end(), comp);
        auto itr = v.begin();
        vector<int> res;
        res.reserve(k);
        while (itr != v.end() && k > 0) {
            res.emplace_back(itr->first);
            itr++;
            k--;
        }

        return res;
    }
};
