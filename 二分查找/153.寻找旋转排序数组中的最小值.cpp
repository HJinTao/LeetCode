#include<LeetCodeStructs.h>
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0,right = nums.size() - 1,res = INT_MAX;
        while(left <= right){
            int mid = left + (right - left) / 2;
            //[left,mid]
            if(nums[mid] >= nums[0]){
                res = min(res,nums[left]);
                left = mid + 1;
            }
            //[mid,right]
            else{
                res = min(res,nums[mid]);
                right = mid - 1;
            }
        }
        return res;
    }
};