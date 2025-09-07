#include<LeetCodeStructs.h>
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();
        vector<int> res(size);
        int left = 0,right = size - 1;
        int index = 0;
        while(index < size){
            if(abs(nums[left]) < abs(nums[right])){
                res[size - 1 - index] = nums[right] * nums[right];
                index++;
                right--;
            }
            else{
                res[size - 1 - index] = nums[left] * nums[left];
                index++;
                left++;
            }
        }
        return res;
    }
};


