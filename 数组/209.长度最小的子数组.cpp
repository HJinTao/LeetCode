#include<LeetCodeStructs.h>
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0,right = 0;
        int sum = 0;
        int res = INT_MAX;
        for(;right < nums.size();right++){
            sum += nums[right];
            while(sum >= target){
                sum -= nums[left];
                res = min(res,right - left + 1);
                left++;
            }
        }
        return res != INT_MAX ? res : 0;
    }
};

