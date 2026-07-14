class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> ada;
        for (int x = 0; x < nums.size(); x++){
            if (ada[nums[x]]){
                return true;
            }else{
                ada[nums[x]] = 1;
            }
        }

        return false;
    }
};