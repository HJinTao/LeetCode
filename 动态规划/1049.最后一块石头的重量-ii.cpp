#include<LeetCodeStructs.h>
class Solution {
public:
    //等价为划分两个子集,要求子集的按元素和之间的差最小
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(),stones.end(),0);
        int ww = sum / 2, n = stones.size();
        vector<int> dp(ww + 1,0);
        for(int i = 0; i < n;i++){
            for(int l = ww; l >= stones[i]; l--){
                dp[l] = max(dp[l],dp[l - stones[i]] + stones[i]);
            }
        }
        return abs(sum - 2 * dp[ww]);

    }
};