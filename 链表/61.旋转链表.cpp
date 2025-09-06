#include<LeetCodeStructs.h>
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;
        ListNode *sentinel = new ListNode(0,head);
        ListNode *p1,*p2;
        int size = 1;
        for(p1 = head; p1->next; p1 = p1->next,size++);
        k %= size;
        p2 = p1;
        p1 = head;
        for(int i = 0; i < size - k - 1; i++)   p1 = p1->next;
        p2->next = sentinel->next;
        sentinel->next = p1->next;
        p1->next = nullptr;
        return sentinel->next;
    }
};

