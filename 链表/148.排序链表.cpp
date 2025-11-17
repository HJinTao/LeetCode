#include<LeetCodeStructs.h>
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        multimap<int,ListNode*> mp;
        for(ListNode* p = head; p != nullptr; p = p->next){
            mp.insert(make_pair(p->val,p));
        }
        ListNode dummy(0);
        ListNode* p = &dummy;
        for(auto kv : mp){
            p->next = kv.second;
            p = p->next;
        }
        p->next = nullptr;
        return dummy.next;
    }
};