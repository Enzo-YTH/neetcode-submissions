class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> maps;
        for (int i = 0; i < nums.size(); i++) {
            if(maps.find(target - nums[i]) != maps.end())
                return {maps[target - nums[i]], i};
            maps[nums[i]] = i;
        }
    }
};
