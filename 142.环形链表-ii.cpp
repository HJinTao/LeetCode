#include<LeetCodeStructs.h>
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head)   return nullptr;
        ListNode* sentinel = new ListNode(0);
        sentinel->next = head;
        ListNode* fast = sentinel;
        ListNode* slow = sentinel;
        do
        {
            fast = fast->next;
            slow = slow->next->next;
        }
        while(fast && slow && slow->next && fast !=slow);
        if(slow && fast && slow->next){
            ListNode* temp = sentinel;
            while(temp != fast){
                temp = temp->next;
                fast = fast->next;
            }
            return fast;
        }
        else{
            return nullptr;
        }
    }
};


