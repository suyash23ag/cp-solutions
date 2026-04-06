// Problem  : Delete Node in a Linked List
// Difficulty: Medium
// Tags     : Linked List
// URL      : https://leetcode.com/problems/delete-node-in-a-linked-list/
// Solved on: 2026-04-07 01:55
// ──────────────────────────────────────────────────

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* target) {
        target->val = target->next->val;
        target->next = target->next->next;

        
    }
};
