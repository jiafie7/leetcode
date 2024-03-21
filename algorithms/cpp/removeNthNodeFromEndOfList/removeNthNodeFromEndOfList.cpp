// Source : https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
// Author : Garfield Zhang
// Date   : 2024-03-21

/****************************************************************************************
 *
 * Given the head of a linked list, remove the nth node from the end of the list and
 * return its head.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        int len = 0;
        for (ListNode* p = dummy; p; p = p->next) len ++ ;
        
        ListNode* p = dummy;
        for (int i = 0; i < len - n - 1; i ++ ) p = p->next;
        p->next = p->next->next;

        return dummy->next;
    }
};


