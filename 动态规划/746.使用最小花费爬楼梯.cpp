#include<LeetCodeStructs.h>
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);  //dp[i]代表从i出发最少花费多少,而不是到达最少花费多少
        dp[0] = cost[0]; dp[1] = cost[1];
        for(int i = 2; i < n; i++){
            dp[i] = min(dp[i - 1],dp[i - 2]) + cost[i];
        }
        return min(dp[n - 1],dp[n - 2]);
    }
};