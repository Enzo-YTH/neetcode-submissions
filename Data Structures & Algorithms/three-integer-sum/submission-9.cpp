class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        int n = nums.size();

        for (int i = 0; i < n - 2; ++i) {
            // Early exit optimization: if the smallest element is > 0, no 3 elements can sum to 0
            if (nums[i] > 0) break;

            // Skip duplicate outer loop elements
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                if (sum == 0) {
                    ret.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    // Skip duplicates for left and right pointers
                    while (l < r && nums[l] == nums[l - 1]) l++;
                    while (l < r && nums[r] == nums[r + 1]) r--;
                } else if (sum < 0) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        return ret;
    }
};