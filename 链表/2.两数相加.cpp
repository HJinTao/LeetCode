#include<LeetCodeStructs.h>
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *sum = new ListNode();
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *p3 = sum;
        int carry = 0;
        while(p1 && p2){
            int s = p1->val + p2->val + carry;
            p3->next = new ListNode(s % 10);
            carry = s / 10;
            p3 = p3->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        while(p1){
            int s = p1->val + carry;
            p3->next = new ListNode(s % 10);
            carry = s / 10;
            p1 = p1->next;
            p3 = p3->next;
        }
        while(p2){
            int s = p2->val + carry;
            p3->next = new ListNode(s % 10);
            carry = s / 10;
            p3 = p3->next;
            p2 = p2->next;
        }
        if(carry){
            p3->next = new ListNode(1);
        }
        return sum->next;
    }
};
