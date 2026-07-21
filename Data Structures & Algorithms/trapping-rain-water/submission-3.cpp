class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int maxi_l = height[l], maxi_r = height[r];
        int sum = 0;
        while (l < r) {
            if (maxi_l > maxi_r) {
                r--;
                maxi_r = max(maxi_r, height[r]);
                sum += maxi_r - height[r];
            }
            else {
                l++;
                maxi_l = max(maxi_l, height[l]);
                sum += maxi_l - height[l];
            }
        }

        return sum;
    }
};
