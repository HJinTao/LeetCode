/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include<LeetCodeStructs.h>
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // 我的解法
        if(!head || !head->next){
            return  head;
        }
        ListNode* sentinel = new ListNode();
        sentinel->next = head;
        ListNode* fast = head;
        ListNode* slow = head->next;
        ListNode* front = sentinel;
        ListNode* behind = slow->next;
        while(true){
            fast->next = behind;
            slow->next = fast;
            front->next = slow;
            front = fast;
            fast = behind;
            if(!fast || !fast->next)
                break;
            slow = fast->next;
            behind = slow->next;
        }
        return sentinel->next;
    }
    ListNode* swapPairs(ListNode* head) {
        // 官方解法 迭代 自写
        if(!head || !head->next){
            return  head;
        }
        ListNode* sentinel = new ListNode();
        sentinel->next = head;
        ListNode* cur = sentinel;
        while(cur->next && cur->next->next){
            ListNode* node1 = cur->next;
            ListNode* node2 = node1->next;
            cur->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            cur = node1;
        }
        return sentinel->next;
    }

    ListNode* swapPairs(ListNode* head) {
        // 官方解法 递归 自写
        if(!head || !head->next){
            return head;
        }
        else{
            ListNode* newHead = head->next;
            head->next = swapPairs(newHead->next);
            newHead->next = head;
            return newHead;
        }
    }
};
// @lc code=end

