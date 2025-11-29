#include<LeetCodeStructs.h>
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0],count = 0;
        for(const int& num : nums){
            count = count >= 0 ? count + num : num;
            res = max(count,res);
        }
        return res;
    }
};