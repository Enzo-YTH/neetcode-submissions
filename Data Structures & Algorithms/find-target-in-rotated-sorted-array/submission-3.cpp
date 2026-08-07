class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) return m;

            // Check if left half is sorted
            if (nums[l] <= nums[m]) {
                if (nums[l] <= target && target < nums[m]) {
                    r = m - 1; // Target in left half
                } else {
                    l = m + 1; // Target in right half
                }
            } 
            // Otherwise, right half is sorted
            else {
                if (nums[m] < target && target <= nums[r]) {
                    l = m + 1; // Target in right half
                } else {
                    r = m - 1; // Target in left half
                }
            }
        }
        return -1;
    }
};