#include <unordered_map>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> map;
        for(auto& n : nums) {
            if(map.count(n))
                return true;
            map[n] = 1;
        }
        return false;
    }
};