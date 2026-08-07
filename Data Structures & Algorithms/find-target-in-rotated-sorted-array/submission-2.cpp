class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1)
            return (nums[0] == target) ? 0 : -1;
        
        int l = 0, r = nums.size() - 1;
        // [5, 6, 7, 0, 1, 2, 3, 4]
        // #1. mid(7) > target(3), m(3) > target(0)
        // #2. mid(6) < target(7), m(0) < target(7)
        while(l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) {
                return m;
            }
            else if (nums[m] > target) {
                if (nums[r] > nums[m]) {
                    r = m - 1;
                }
                else if (nums[l] > target) {
                    l = m + 1;
                }
                else {
                    r = m - 1;
                }
            }
            else { // nums[m] < target
                if (nums[l] < nums[m]) {
                    l = m + 1;
                }
                else if (nums[r] < target) {
                    r = m - 1;
                }
                else {
                    l = m + 1;
                }
            }
        }

        return -1;
    }
};
