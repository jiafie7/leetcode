// Source : https://leetcode.com/problems/swap-nodes-in-pairs/
// Author : Garfield Zhang
// Date   : 2024-03-26

/****************************************************************************************
 *
 * Given a linked list, swap every two adjacent nodes and return its head. You must 
 * solve the problem without modifying the values in the list's nodes 
 * (i.e., only nodes themselves may be changed.)
 *
 ****************************************************************************************/

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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        for (ListNode* p = dummy; p->next && p->next->next; ) {
            ListNode* a = p->next;
            ListNode* b = a->next;
            p->next = b;
            a->next = b->next;
            b->next = a;
            p = a;
        }

        return dummy->next;
    }
};
