#include<LeetCodeStructs.h>
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow = reverseList(slow);
        ListNode *p = head;
        while(p && slow){
            p = p->next;
            slow = slow->next;
            if(p->val != slow->val){
                return false;   
            }
        }
        return true;
    }

    ListNode* reverseList(ListNode* head){
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* next;
        while(cur){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

    // bool isPalindrome(ListNode* head) {
    //     ListNode* p = head;
    //     vector<int> nums;
    //     while(p){
    //         nums.push_back(p->val);
    //         p = p->next;
    //     }
    //     int i = 0, j = nums.size() - 1;
    //     while(i < j){
    //         if(nums[i] != nums[j]){
    //             return false;
    //         }
    //         i++;
    //         j--;
    //     }
    //     return true;
    // }
};
