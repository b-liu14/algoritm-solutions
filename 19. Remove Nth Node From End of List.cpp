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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* p = head;
        while(p) {
            len ++;
            p = p->next;
        }
        if (len == n) {
            return head->next;
        }
        p = head;
        for (int i = 1; i < len - n; i ++) {
            p = p->next;
        }
        p->next = p->next->next;
        return head;
    }
};
