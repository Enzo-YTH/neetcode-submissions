class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0;
        // [1, 2]
        // ans ^= [0, 1, 1, 2, 2]
        for (int i = 0; i < nums.size(); ++i) {
            ans ^= i;
            ans ^= nums[i];
        }
        ans ^= nums.size();

        return ans;
    }
};
