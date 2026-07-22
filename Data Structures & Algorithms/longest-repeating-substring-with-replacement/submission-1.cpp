class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, maxi = 0;
        vector<int> table(26, 0);
        table[s[0] - 'A'] = 1;
        while (l <= r && r < s.size()) {
            int freq_cnt = *std::max_element(table.begin(), table.end());
            int window = r - l + 1;
            if (window - freq_cnt <= k) {
                maxi = (window > maxi) ? window : maxi;
                r++;
                if (r >= s.size()) {
                    break;
                }
                table[s[r] - 'A'] += 1;

            }
            else {
                table[s[l] - 'A'] -= 1;
                l++;
                if (l > r) {
                    r++;
                    if (r >= s.size()) {
                        break;
                    }
                    table[s[r] - 'A'] += 1;
                }  
            }
        }
        return maxi;
    }
};
//
