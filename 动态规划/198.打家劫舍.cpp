#include<LeetCodeStructs.h>
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1){
            return nums[0];
        }
        vector<int> dp(n);   //dp[i]代表[0,i - 1]抢劫最大利润
        dp[0] = nums[0];  dp[1] = max(nums[0],nums[1]);
        for(int i = 2; i < n; i++){
            int p1 = nums[i] + dp[i - 2],p2 = dp[i - 1];
            dp[i] = max(p1,p2);     //只有两种情况,类似爬楼梯的递推数列
        }
        return dp[n - 1];
    }
};