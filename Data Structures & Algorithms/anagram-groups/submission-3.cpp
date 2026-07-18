class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.empty()) return {};

        std::unordered_map<string, vector<string>> maps;
        for (auto& s : strs) {  // 1. Pass by reference to avoid copying
            string sorted_s = s;
            std::sort(sorted_s.begin(), sorted_s.end());
            maps[sorted_s].push_back(s);           
        }
        vector<vector<string>> res;
        res.reserve(maps.size());  // 2. Pre-allocate memory to avoid reallocation overhead
        for (auto& [key, value] : maps) {
            res.push_back(std::move(value));  // 3. Use std::move to transfer ownership instantly without copying vectors
        }
        return res;
    }
};
