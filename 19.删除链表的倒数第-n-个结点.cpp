#include<LeetCodeStructs.h>
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* sentinel = new ListNode();
        sentinel->next = head;
        ListNode* fast = sentinel;
        ListNode* slow = sentinel;
        for(int i = -1; i < n - 1; i++){
            slow = slow->next;
        }
        while(slow->next){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* temp = fast->next;
        fast->next = temp->next;
        delete temp;
        return sentinel->next;
    }
};
// @lc code=end

