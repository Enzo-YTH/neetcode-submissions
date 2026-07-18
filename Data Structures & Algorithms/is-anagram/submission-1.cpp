class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;

        int char_cnt[26] = {0};
        for (auto ch : s) {
            char_cnt[ch - 'a'] += 1;
        }
        for (auto ch : t) {
            char_cnt[ch - 'a'] -= 1;
            if(char_cnt[ch - 'a'] < 0)
                return false;
        }
        return true;
    }
};
