/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Divide and Conquer
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* h = new ListNode(0);
        ListNode* p = h;
        while(l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            }
            else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if (l1) {
            p->next = l1;
        }
        else {
            p->next = l2;
        }
        return h->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) return NULL;
        if (n == 1) return lists[0];
        if (n == 2) return mergeTwoLists(lists[0], lists[1]);
        int middle = n / 2;
        vector<ListNode*> l2;
        for (int i = 0; i < middle; i ++) {
            l2.push_back(lists.back());
            lists.pop_back();
        }
        return mergeTwoLists(mergeKLists(lists), mergeKLists(l2));
    }
};
