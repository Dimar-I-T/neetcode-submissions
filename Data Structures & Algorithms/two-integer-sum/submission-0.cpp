class Solution {
public:
    int mapVal(unordered_map<int, int> &um, int key) {
        auto itr = um.find(key);
        if (itr != um.end()) {
            return itr->second;
        } else {
            return -1;
        }
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;
        int n = nums.size();
        um.reserve(n);
        vector<int> hasil(2);
        for (int x = 0; x < n; x++) {

            cout << "target - nums[x]: " << target - nums[x] << "\n";
            int idx = mapVal(um, target - nums[x]);
            cout << "idx target: " << idx << "\n";
            if (idx != -1) {
                cout << "ADA" << "\n";
                hasil[0] = idx;
                hasil[1] = x;
                break;
            }

            cout << "x: " << x << "\n";
            cout << "nums[x]: " << nums[x] << "\n";
            int idx0 = mapVal(um, nums[x]);
            cout << "idx0: " << idx0 << "\n";
            if (idx0 == -1) {
                um[nums[x]] = x; 
            }
            
            cout << "\n";
        }

        return hasil;
    }
};
