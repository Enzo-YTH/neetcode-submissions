class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        int i = 0;
        while (i < nums.size() - 2) {
            int l = i + 1, r = nums.size() - 1;
            if (i > 0 && nums[i] == nums[i - 1]) {
                i++;
                continue;
            }
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    ret.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l < r && nums[l - 1] == nums[l]) l++;
                    while (l < r && nums[r + 1] == nums[r]) r--;
                }
                else if (sum < 0) {
                    l++;
                }
                else {
                    r--;
                }
            }
            i++;
        }
        
        return ret;
    }
};
