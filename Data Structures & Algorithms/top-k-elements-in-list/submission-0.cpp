class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // #1. create maps to record the times of each num
        std::unordered_map<int, int> maps;
        for(auto n : nums) {
            maps[n] += 1;
        }

        // #2. gather each element
        std::vector<std::vector<int>> vec(nums.size() + 1);
        for (const auto& pair : maps) {
            vec[pair.second].push_back(pair.first);
        }

        // #3. collect top k
        std::vector<int> ret;
        for (int i = vec.size() - 1; i >= 0; i--) {
            if((vec[i]).empty())
                continue;
            if(!k)
                return ret;
            ret.insert(ret.end(), vec[i].begin(), vec[i].end());
            k -= vec[i].size();
        }
        return ret;
    }
};
