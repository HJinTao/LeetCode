#include<LeetCodeStructs.h>
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
    }

    /*暴力解法*/
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     if(!headA || !headB)   
    //         return nullptr;
    //     ListNode* p1 = headA;
    //     ListNode* p2 = headB;
    //     while(p1){
    //         p2 = headB;
    //         while(p2){
    //             if(p1 == p2)
    //                 return p1;   
    //             p2 = p2->next;             
    //         }                
    //         p1 = p1->next;
    //     }
    //     return nullptr;
    // }
};
// @lc code=end

