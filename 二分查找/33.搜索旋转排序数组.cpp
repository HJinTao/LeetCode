#include<LeetCodeStructs.h>
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1,start = nums[0];
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                return mid;
            }
            // [left,mid]有序
            if(nums[mid] >= start){
                //所谓二分就是在裁减区间,第一个分支裁剪掉的是有序的区间,第二个分支裁剪的是无序的区间
                if(target >= nums[left] && target <= nums[mid]){
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
            // [mid,right]有序
            else{
                if(target >= nums[mid] && target <= nums[right]){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};