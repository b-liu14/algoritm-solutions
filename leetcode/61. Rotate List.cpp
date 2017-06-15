/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // Link the tail to head make things simpler.
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        ListNode* tail = head;
        int len = 1;
        while (tail->next) {
            tail = tail->next;
            len ++;
        }
        tail->next = head;
        ListNode* newTail = head;
        for (int i = 0; i < len - k % len - 1; i ++) {
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next;
        newTail->next = NULL;
        return newHead;
    }
};
