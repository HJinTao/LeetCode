#include<LeetCodeStructs.h>
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0)    
            return {-1,-1}; 
        return {leftBound(nums,target),rightBound(nums,target)};
    }


    /*寻找第一个>=target的索引,[left,right]写法*/
    int leftBound(vector<int> &nums,int target){
        int left = 0,right = nums.size() - 1;
        int mid;
        while(left <= right){
            mid = left + (right - left) / 2;
            if(nums[mid] == target){
                right = mid - 1;
            }
            else if(nums[mid] < target){
                left = mid + 1;
            }
            else if(nums[mid] > target){
                right = mid - 1;
            }
        }
        return left < nums.size() && nums[left] == target ? left : -1;  // 防止left溢出
    }

    int rightBound(vector<int> &nums,int target){
        int left = 0,right = nums.size() - 1;
        int mid;
        while(left <= right){
            mid = left + (right - left) / 2;
            if(nums[mid] == target){
                left = mid + 1;
            }
            else if(nums[mid] < target){
                left = mid + 1;
            }
            else if(nums[mid] > target){
                right = mid - 1;
            }
        }
        return right >= 0 && nums[right] == target ? right : -1;  // 防止right溢出
    }
};

