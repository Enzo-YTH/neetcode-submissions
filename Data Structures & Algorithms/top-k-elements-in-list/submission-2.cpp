class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // #1. Count the frequency of each number
        std::unordered_map<int, int> maps;
        for(auto n : nums) {
            maps[n] += 1;
        }

        // #2. Bucket sort: distribute elements based on their frequency
        std::vector<std::vector<int>> vec(nums.size() + 1);
        for (const auto& pair : maps) {
            vec[pair.second].push_back(pair.first);
        }

        // #3. Collect the top k frequent elements
        std::vector<int> ret;
        for (int i = vec.size() - 1; i >= 0; i--) {

            if(!k)
                return ret;
            ret.insert(ret.end(), vec[i].begin(), vec[i].end());
            k -= vec[i].size();
        }
        return ret;
    }
};
