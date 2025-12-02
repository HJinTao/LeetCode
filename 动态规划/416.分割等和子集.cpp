#include<LeetCodeStructs.h>
class Solution {
public:
    //等价为是否能划分出一个和为sum/2的子集
    //可以转化为0-1背包问题,value和weight均为nums[i],判断能否装满背包
    bool canPartition(vector<int>& nums) {
        int sum = 0,n = nums.size();
        for(const int& num : nums)  sum += num;
        if(sum % 2)  return false;
        int p = sum / 2;
        vector<int> dp(p + 1,0);
        for(int i = 0; i < n;i++){
            for(int l = p; l >= nums[i]; l--){
                dp[l] = max(dp[l],dp[l - nums[i]] + nums[i]);
            }
        }
        return dp[p] == p;
    }
};