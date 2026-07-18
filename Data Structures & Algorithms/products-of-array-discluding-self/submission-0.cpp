class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> forward(nums.size(), 1);
        vector<int> backward(nums.size(), 1);
        int f = 1, b = 1;
        for(int i = 0; i < nums.size(); i++) {
            forward[i] = f;
            f *= nums[i];
            backward[nums.size() - i - 1] = b;
            b *= nums[nums.size() - i - 1];
        }
        for(int i = 0; i < nums.size(); i++) {
            forward[i] *= backward[i];
        }

        return forward;
    }
};