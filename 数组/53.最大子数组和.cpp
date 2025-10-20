#include<LeetCodeStructs.h>
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int leftMin = nums[0];
        for(int i = 1; i < nums.size(); i++){
            nums[i] += nums[i - 1];
            res = max(res,nums[i] - leftMin);
            res = max(res,nums[i]);
            leftMin = min(nums[i],leftMin);
        }
        return res;        
    }
};