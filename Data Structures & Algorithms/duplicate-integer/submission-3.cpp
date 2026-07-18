class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> sets;
        for (int num : nums) {
            if(sets.find(num) != sets.end())
                return true;
            sets.insert(num);
        }
        return false;
    }
};