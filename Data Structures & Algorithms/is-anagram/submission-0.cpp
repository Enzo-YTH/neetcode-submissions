class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> maps;
        for(auto ch : s) {
            maps[ch] += 1;
        }
        for(auto ch : t) {
            if(maps[ch] == 0)
                return false;
            else
                maps[ch] -= 1;
            if(maps[ch] == 0)
                maps.erase(ch);
        }
        if(maps.empty())
            return true;
        else
            return false;
    }
};
