class Solution {
public:
    int reverse(int x) {
        
        int res = 0;

        while (x) {

            int pop = x % 10;

            if ((res > INT_MAX / 10) || ((res == (INT_MAX / 10)) && pop > (INT_MAX % 10))) {
                return 0;
            }
            else if ((res < INT_MIN / 10) || ((res == (INT_MIN / 10)) && pop < (INT_MIN % 10))) {
                return 0;
            }

            res = res * 10 + pop;

            x /= 10;
        }

        return res;
    }
};
