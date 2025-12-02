#include<LeetCodeStructs.h>
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(),res = nums[0];
        //维护两个状态,minF[i]表示以nums[i]结尾的最小子数组乘积,maxF[i]同理
        vector<int> minF(nums.begin(),nums.end()),maxF(nums.begin(),nums.end());
        for(int i = 1; i < n; i++){
            maxF[i] = max({nums[i],minF[i - 1] * nums[i],maxF[i - 1] * nums[i]});
            minF[i] = min({nums[i],minF[i - 1] * nums[i],maxF[i - 1] * nums[i]});
            res = max(maxF[i],res);
        }
        return res;
    }
};