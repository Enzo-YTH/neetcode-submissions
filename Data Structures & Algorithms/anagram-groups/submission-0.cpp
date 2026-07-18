class Solution {
public:
    string encoding(string str) {
        int v[26] = {0};
        string res = "";
        for (auto c : str) {
            v[c - 'a'] += 1;
        }
        for (int i = 0; i < 26; i++) {
            if(v[i] == 0)
                continue;
            res.push_back('a' + i);
            res.push_back(v[i]);
        }

        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.empty())
            return {{""}};
        std::unordered_map<string, vector<string>> maps;
        for (auto s : strs) {
            auto temp = encoding(s);
            maps[temp].push_back(s);           
        }
        vector<vector<string>> res;
        for (auto& [key, value] : maps) {
            res.push_back(value);
        }
        return res;
    }
};
