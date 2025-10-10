#include<LeetCodeStructs.h>
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int left = nums.size() - 2;
        int right = nums.size() - 1;
        while(left >= 0 && nums[left] >= nums[left + 1]){
            left--;
        }
        if(left >= 0){
            while(nums[right] <= nums[left]){
                right--;
            } 
            swap(nums[left],nums[right]);
        }
        reverse(nums.begin() + left + 1,nums.end());  // [begin,end)
    }
};

