class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi = 0;
        int start = 0;
        int i = 0;
        std::unordered_map<char, int> maps;
        for (auto& c : s) {
            
            if (maps.find(c) != maps.end()) {
                start = max(maps[c] + 1, start);
            }

            maps[c] = i;
            maxi = max(maxi, i - start + 1);
            i++;
            
        }

        return maxi;
    }
};
