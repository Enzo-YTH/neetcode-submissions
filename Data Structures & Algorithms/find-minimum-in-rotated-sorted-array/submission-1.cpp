class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums[0] <= nums[nums.size() - 1]) 
            return nums[0];
        
        int maxi = nums[0], maxi_idx = 0;
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] >= maxi) {
                maxi = nums[m];
                maxi_idx = m;
                l = m + 1;
            }
            else if (nums[m] < maxi) {
                r = m - 1;
            }
        }

        return nums[maxi_idx + 1];
    }
};
