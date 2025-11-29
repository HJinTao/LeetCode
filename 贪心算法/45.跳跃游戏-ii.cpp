#include<LeetCodeStructs.h>
class Solution {
public:
    //[0,end]都是可以到达的地方,贪心的地方就是走最小的步数让end尽可能的大
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 0;
        }
        int cur = 0, end = nums[0],res = 1;
        while(end < n - 1){
            int tend = end;      //类似滑动窗口
            for(int i = cur; i <= tend; i++){
                end = max(end,nums[i] + i);
            }
            cur = tend;
            res++;
        }
        return res;
    }
};