#include<LeetCodeStructs.h>
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1){
            return n;
        }
        int p = nums[0] - nums[1];
        int res = p ? 2 : 1;
        for(int i = 1; i < n - 1; i++){
            int cur = nums[i] - nums[i + 1];   
            if((cur < 0 && p >= 0) || (cur > 0 && p <= 0)){
                p = cur;
                res++;   //把[i,i+1]长度也就是1加入res
            }
        }
        return res;
    }
};