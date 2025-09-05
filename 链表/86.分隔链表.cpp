#include<LeetCodeStructs.h>
class Solution {
public:
    /*O(1)额外空间复杂度*/
    ListNode* partition(ListNode* head, int x) {
        if(!head)   
            return head;
        ListNode dummyA(0),dummyB(0),*pA = &dummyA,*pB = &dummyB,*p = head;
        while(p){
            ListNode *temp;
            if(p->val < x){
                pA->next = p;
                pA = pA->next;
            }
            else{
                pB->next = p;
                pB = pB->next;
            }
            p = p->next;
        }
        pB->next = nullptr;
        pA->next = dummyB.next;
        return dummyA.next;
        
    }

    /*O(N)额外空间复杂度*/
    // ListNode* partition(ListNode* head, int x) {
    //     if(!head)   return head;
    //     ListNode sentinel(0),*p1 = &sentinel,*p2 = head;
    //     sentinel.next = head;
    //     while(p2){
    //         if(p2->val < x){
    //             p1->next = new ListNode(p2->val);
    //             p1 = p1->next;
    //         }
    //         p2 = p2->next;
    //     }
    //     p2 = head;
    //     while(p2){
    //         if(p2->val >= x){
    //             p1->next = new ListNode(p2->val);
    //             p1 = p1->next;
    //         }
    //         p2 = p2->next;
    //     }
    //     p1->next = nullptr;
    //     return sentinel.next;
    // }
};

