class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        int xor_num = 0;
        for (int n : nums) {
            xor_num ^= n;
        }

        return xor_num;
    }
};
