class Solution {
public:
    int search(vector<int>& nums, int target) {
        //if (nums.size() == 0)  return -1;

        // [1, 2, 3, 4, 5], targ = 4
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
                int mid = (left + right) / 2;
                if (nums[mid] == target)
                    return mid;
                else if (nums[mid] > target) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
        }
        return -1;
    }
};
