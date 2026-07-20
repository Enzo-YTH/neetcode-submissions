class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {
        // #1. Sort a vector
        sort(nums.begin(), nums.end());

        // #2. Two sum
        vector<vector<int>> ret;
        int i = 0;
        while (i < nums.size() - 2) {
            int l = i + 1, r = nums.size() - 1;
            int prev_l, prev_r;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    ret.push_back({nums[i], nums[l], nums[r]});
                    prev_l = nums[l];
                    prev_r = nums[r];
                    l++;
                    r--;
                    while((l < r) && (prev_l == nums[l])) l++;
                    while((l < r) && (prev_r == nums[r])) r--;
                }        
                else if (sum < 0) {
                    prev_l = nums[l];
                    l++;
                    while((l < r) && (prev_l == nums[l])) l++;
                }
                else {
                    prev_r = nums[r];
                    r--;
                    while((l < r) && (prev_r == nums[r])) r--;
                }
            }
            i++;
            while((i < nums.size() - 2) && (nums[i - 1] == nums[i])) i++;
        }

        return ret;
    }
};
