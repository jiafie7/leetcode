// Source : https://leetcode.com/problems/reverse-nodes-in-k-group/
// Author : Garfield Zhang
// Date   : 2024-03-26

/****************************************************************************************
 *
 * Given the head of a linked list, reverse the nodes of the list k at a time, and 
 * return the modified list.
 *
 * k is a positive integer and is less than or equal to the length of the linked list.
 * If the number of nodes is not a multiple of k then left-out nodes, in the end,
 * should remain as it is.
 *
 * You may not alter the values in the list's nodes, only nodes themselves may be changed.
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        for (ListNode *p = dummy; ;) {
            ListNode *q = p;
            for (int i = 0; i < k && q; i ++ ) q = q->next;
            if (!q) break;
            ListNode *a = p->next, *b = a->next;
            for (int i = 0; i < k - 1; i ++ ) {
                ListNode *c = b->next;
                b->next = a;
                a = b, b = c;
            }
            ListNode *c = p->next;
            p->next = a;
            c->next = b;
            p = c;
        }
        return dummy->next;
    }
};