class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> sets;
        for(auto n : nums) {
            if(sets.find(n) != sets.end())
                return true;
            sets.insert(n);
        }
        return false;
    }
};