/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<LeetCodeStructs.h>
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) 
            return false;
        ListNode* sentinel = new ListNode(0,head);
        ListNode* fast = sentinel;
        ListNode* slow = sentinel;
        do{
            fast = fast->next;
            slow = slow->next->next;
        }while(fast && slow && slow->next && fast != slow);
        return fast && slow && slow->next ? true : false;
    }
};
// @lc code=end

