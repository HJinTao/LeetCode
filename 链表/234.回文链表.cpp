#include<LeetCodeStructs.h>
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* p = head;
        vector<int> nums;
        while(p){
            nums.push_back(p->val);
            p = p->next;
        }
        int i = 0, j = nums.size() - 1;
        while(i < j){
            if(nums[i] != nums[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
