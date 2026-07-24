class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.size() > s2.size()) {
            return false;
        }
        else if (s1 == s2) {
            return true;
        }

        int s1_table[26] = {0};
        int s2_table[26] = {0};

        // #1. count s1, s2
        for (int i = 0; i < s1.size(); i++) {
            s1_table[s1[i] - 'a'] += 1;
            s2_table[s2[i] - 'a'] += 1;
        }

        // #2. sliding window
        int window_size = s1.size();
        int match = 0;

        for (int i = 0; i < 26; i++) {
            if (s1_table[i] == s2_table[i])
                match += 1;
        }

        for (int i = 1; i <= s2.size() - window_size; i++) {
            if (match == 26)
                return true;

            if (s2_table[s2[i + window_size - 1] - 'a'] == s1_table[s2[i + window_size - 1] - 'a']) {
                match -= 1;
            }
            else {
                if (s2_table[s2[i + window_size - 1] - 'a'] == (s1_table[s2[i + window_size - 1] - 'a'] - 1)) {
                    match += 1;
                }
            }
            s2_table[s2[i + window_size - 1] - 'a'] += 1;

            if (s2_table[s2[i - 1] - 'a'] == s1_table[s2[i - 1] - 'a']) {
                match -= 1;
                s2_table[s2[i - 1] - 'a'] -= 1;
            }
            else {
                s2_table[s2[i - 1] - 'a'] -= 1;
                if (s2_table[s2[i - 1] - 'a'] == s1_table[s2[i - 1] - 'a']) {
                    match += 1;
                }
            }
            printf("match:%d\n", match);
        }

        return (match == 26) ? true : false;
    }
};
