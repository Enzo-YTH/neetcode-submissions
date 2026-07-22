class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> table(26, 0);
        int l = 0, maxi = 0, max_freq = 0;

        for (int r = 0; r < s.size(); ++r) {
            // 1. Expand window: add current character
            table[s[r] - 'A']++;
            max_freq = max(max_freq, table[s[r] - 'A']);

            // 2. Shrink window: if invalid, shift left pointer once
            while ((r - l + 1) - max_freq > k) {
                table[s[l] - 'A']--;
                l++;
            }

            // 3. Track largest valid window size
            maxi = max(maxi, r - l + 1);
        }

        return maxi;
    }
};