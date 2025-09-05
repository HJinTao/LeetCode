#include<LeetCodeStructs.h>
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* p1 = list1;
        ListNode* p2 = list2;
        ListNode* sentinenl = new ListNode(0);
        ListNode* p3 = sentinenl;
        while(p1 && p2){
            if(p1->val <= p2->val){
                p3->next = p1;
                p1 = p1->next;
            }
            else{
                p3->next = p2;
                p2 = p2->next;
            }
            p3 = p3->next;
        }
        if(p1){
            p3->next = p1;
        }
        else if (p2){
            p3->next = p2;
        }
        else{
            p3->next = nullptr;
        }
        return sentinenl->next;
    }
};

