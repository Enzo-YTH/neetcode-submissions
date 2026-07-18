class Solution {
public:
    bool check_abc(char c) {
        if ( (c >= 'a' && c <= 'z') ||
             (c >= 'A' && c <= 'Z') ||
             (c >= '0' && c <= '9') )
             return true;
        return false;
    }
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while(l < r) {
            while(!check_abc(s[l])) {
                l++;
                if(l >= r) return true;
            }
            while(!check_abc(s[r])) {
                r--;
                if(l >= r) return true;
            }
            if(std::tolower(s[l]) != std::tolower(s[r])) return false;
            l++;
            r--;
        }
        return true;
    }
};
