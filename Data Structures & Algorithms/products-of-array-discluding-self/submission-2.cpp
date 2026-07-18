class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n_size = nums.size();
        vector<int> forward(n_size, 1);
        int f = 1;
        for(int i = 0; i < n_size; i++) {
            forward[i] = f;
            f *= nums[i];
        }
        f = 1;
        for(int i = n_size - 1; i >= 0; i--) {
            forward[i] *= f;
            f *= nums[i];
        }

        return forward;
    }
};