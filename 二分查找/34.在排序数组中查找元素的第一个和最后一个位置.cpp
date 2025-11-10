#include<LeetCodeStructs.h>
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty())  return {-1,-1}; 
        vector<int> res(2);
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        // find lowerBound    
        // 维护[left,right],[0,left) < target  (right,n-1] >= target
        // 退出时 left = right + 1
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        res[0] = left < n && nums[left] == target ? left : -1;

        // find higherBound
        left = 0;
        right = n - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] > target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        res[1] = right >= 0 && nums[right] == target ? right : -1;
        return res;
    }
};