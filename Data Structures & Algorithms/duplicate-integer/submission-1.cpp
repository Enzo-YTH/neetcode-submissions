class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::map<int, bool> map;
        int i = 0;
        for (int num : nums) {
            if(map[num])
                return true;
            map[num] = true;
        }
        return false;
    }
};