#include<LeetCodeStructs.h>
class Solution {
    public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];    // 环形链表,控制初始位置一致.若0,则下面的重置位置也应该为0
        int fast = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(fast != slow);
        
        slow = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }   
};

