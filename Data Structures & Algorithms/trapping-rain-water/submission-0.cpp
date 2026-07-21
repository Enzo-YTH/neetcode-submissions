class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int maxi_l = height[l], maxi_r = height[r];
        int sum = 0;
        while (l < r) {
            if (maxi_l > maxi_r) {
                r--;
                if (maxi_r - height[r] >= 0) {
                    sum += maxi_r - height[r];
                }
                else {
                    maxi_r = height[r];
                }
            }
            else {
                l++;
                if (maxi_l - height[l] >= 0) {
                    sum += maxi_l - height[l];
                }
                else {
                    maxi_l = height[l];
                }
            }
        }

        return sum;
    }
};
