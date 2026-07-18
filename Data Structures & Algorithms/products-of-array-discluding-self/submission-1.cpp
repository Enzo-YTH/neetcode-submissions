class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n_size = nums.size();
        vector<int> forward(n_size, 1);
        vector<int> backward(n_size, 1);
        int f = 1, b = 1;
        for(int i = 0; i < n_size; i++) {
            forward[i] = f;
            f *= nums[i];
            backward[n_size - i - 1] = b;
            b *= nums[n_size - i - 1];
        }
        for(int i = 0; i < n_size; i++) {
            forward[i] *= backward[i];
        }

        return forward;
    }
};