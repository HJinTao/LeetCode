#include<LeetCodeStructs.h>
class Solution {
public:
    //[0,end]都是可以到达的地方,贪心的地方就是让end尽可能的大
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return true;
        }
        int cur = 0,end = nums[0];
        while(cur < end){
            cur++;
            end = max(cur + nums[cur],end);
            if(end >= n - 1){
                return true;
            }
        }
        return false;
    }
};