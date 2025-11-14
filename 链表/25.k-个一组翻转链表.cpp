#include<LeetCodeStructs.h>
class Solution {
public:
    
    //  O(1)空间复杂度解法
    ListNode* reverseKGroup(ListNode* head, int k){
        int size = 0;
        for(ListNode* p = head; p != nullptr; p = p->next){
            size++;
        }
        ListNode dummy = ListNode(0);
        ListNode* l = head;
        ListNode* r = head;
        ListNode* p = &dummy;
        int cnt = size / k;
        for(int i = 0; i < cnt; i++){
            for(int j = 0; j < k; j++, r = r->next);
            p->next = reverseList(l,r);
            p = l;
            l = r;
        }
        p->next = l;
        return dummy.next;
    }

    ListNode* reverseList(ListNode* head, ListNode* end){
        //左闭右开
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* next;
        while(cur != end){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

    //  O(K)空间复杂度解法
    ListNode* reverseKGroupOK(ListNode* head, int k) {
        int size = 0;
        ListNode* p = head;
        while(p){
            p = p->next;
            size++;
        }
        int cnt = size / k;
        ListNode* p1 = head;
        ListNode* dummy = new ListNode(0);
        ListNode* p2 = dummy;
        for(int i = 0; i < cnt; i++){
            stack<ListNode*> st;
            for(int j = 0; j < k; j++){
                st.push(p1);
                p1 = p1->next;
            }
            while(!st.empty()){
                p2->next = st.top();
                st.pop();
                p2 = p2->next;
            }
        }
        p2->next = p1;
        return dummy->next;
    }
};


