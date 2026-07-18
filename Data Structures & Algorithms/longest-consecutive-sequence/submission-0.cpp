class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_map<int, int> maps;
        for(const auto& n : nums) {
            if(maps[n] != 0 && maps.find(n) != maps.end())
                continue;
            int update_val = maps[n - 1] + maps[n + 1] + 1;
            maps[n - maps[n - 1]] = update_val;
            maps[n + maps[n + 1]] = update_val;
            maps[n] = update_val;
        }

        int maxi = 0;
        for(const auto& [key, value] : maps) {
            if(value > maxi) maxi = value;
        }

        return maxi;
    }
};