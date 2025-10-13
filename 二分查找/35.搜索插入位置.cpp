#include<LeetCodeStructs.h>
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int mid;
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            mid = left + (right - left) / 2;
            if(nums[mid] < target){
                left = mid + 1;
            }
            else if(nums[mid] > target){
                right = mid - 1;
            }
            else{
                return mid;
            }
            return left;
        }
    }
};

