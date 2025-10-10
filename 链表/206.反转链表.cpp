#include<LeetCodeStructs.h>
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //重写,改用pre cur next 明确cur的含义是当前要更改方向的节点
        ListNode *pre = nullptr;
        ListNode *cur = head;
        ListNode *next;
        while(cur){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};