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
    ListNode* swapPairs(ListNode* head) {
        ListNode* parentNode = new ListNode(0);
        parentNode->next = head;
        ListNode* p = head;
        while(p && p->next) {
            ListNode* q = p->next;
            p->next = q->next;
            q->next = p;
            parentNode->next = q;
            if (p == head) {
                head = q;
            }
            parentNode = p;
            p = p->next;
        }
        return head;
    }
};
