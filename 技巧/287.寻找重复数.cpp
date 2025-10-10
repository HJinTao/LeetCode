#include<LeetCodeStructs.h>
class Solution {
    public:
    int findDuplicate(vector<int>& nums) {
        // 位运算 寻找充要条件x > y
        int n = nums.size() - 1;
        int bits = 0;
        while(n){
            bits++;
            n >>= 1;
        }
        int res = 0;
        for(int bit = 0; bit < bits; bit++){
            int x = 0;
            int y = 0;
            for(int i = 0; i < nums.size(); i++){
                x += !!(nums[i] & (1 << bit));
                y += !!(i & (1 << bit));
            }
            res = x > y ? res | (1 << bit) : res;
        }
        return res;
    }   

    // int findDuplicate(vector<int>& nums) {
    //     int slow = nums[0];    // 环形链表,控制初始位置一致.若0,则下面的重置位置也应该为0
    //     int fast = nums[0];
    //     do{
    //         slow = nums[slow];
    //         fast = nums[nums[fast]];
    //     }while(fast != slow);
        
    //     slow = nums[0];
    //     while(slow != fast){
    //         slow = nums[slow];
    //         fast = nums[fast];
    //     }
    //     return slow;
    // }   
};

