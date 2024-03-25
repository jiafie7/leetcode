// Source : https://leetcode.com/problems/merge-k-sorted-lists/description/
// Author : Garfield Zhang
// Date   : 2024-03-25

/****************************************************************************************
 *
 * You are given an array of k linked-lists lists, each linked-list is sorted 
 * in ascending order.
 *
 * Merge all the linked-lists into one sorted linked-list and return it.
 *
 ****************************************************************************************/

class Solution {
public:
    struct Cmp {
        bool operator() (ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Cmp> heap;
        ListNode *dummy = new ListNode(-1), *tail = dummy;
        for (ListNode* p: lists) if (p) heap.push(p);

        while (heap.size()) {
            ListNode* t = heap.top();
            heap.pop();

            tail = tail->next = t;
            if (t->next) heap.push(t->next);
        }
        return dummy->next;
    }
};