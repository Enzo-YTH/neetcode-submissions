class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;
        int maxi = 0;
        while (l < r) {
            int h = heights[l] > heights[r] ? heights[r] : heights[l];
            if ((r - l) * h > maxi) {
                maxi = (r - l) * h;
            }
            if (heights[l] > heights[r]) r--;
            else l++;
        }

        return maxi;
    }
};
// [1,7,2,5,4,7,3,6]
