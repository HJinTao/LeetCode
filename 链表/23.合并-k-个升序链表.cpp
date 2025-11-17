#include<LeetCodeStructs.h>
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode res(0);
        ListNode* idx = &res;
        bool allMerged = false;
        multimap<int,ListNode*> mp;
        while(!allMerged){
            allMerged = true;
            for(ListNode* &l : lists){
                if(l){
                    mp.insert(make_pair(l->val,l));
                    l = l->next;
                }
                allMerged &= !l;
            }
        }
        for(auto kv : mp){
            idx->next = kv.second;
            idx = idx->next;
        }
        return res.next;
    }
};

