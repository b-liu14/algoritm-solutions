// Redundant Solution:
class Solution {
public:
    ListNode* reverse(ListNode* l) {
        ListNode* p = l;
        ListNode* pnext = p->next;
        while(pnext != NULL) {
            ListNode* pnn = pnext->next;
            pnext->next = p;
            p = pnext;
            pnext = pnn;
        }
        return p;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//        l1 = reverse(l1);
//        l2 = reverse(l2);
        ListNode*  h = NULL;
        ListNode* p = NULL;
        ListNode* q = NULL;
        int c = 0;
        while(l1 != NULL && l2 != NULL) {
            int s = l1->val + l2->val + c;
            q = new ListNode(s % 10);
            c = s / 10;
            if(h == NULL) {
                h = q;
            }
            else {
                p->next = q;
            }
            p = q;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL) {
            int s = l1->val + c;
            q = new ListNode(s % 10);
            c = s / 10;
            p->next = q;
            p = q;
            l1 = l1->next;
        }
        while(l2 != NULL) {
            int s = l2->val + c;
            q = new ListNode(s % 10);
            c = s / 10;
            p->next = q;
            p = q;
            l2 = l2->next;
        }
        if (c != 0) {
            q = new ListNode(c);
            p->next = q;
        }
        return h;
    }
};

// short solution:
//class Solution {
//public:
//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//        //        l1 = reverse(l1);
//        //        l2 = reverse(l2);
//        ListNode*  h = new ListNode(0);
//        ListNode* p = h;
//        int c = 0;
//        while(l1 != NULL || l2 != NULL || c != 0) {
//            int s = (l1?l1->val:0) + (l2?l2->val:0) + c;
//            p->next = new ListNode(s % 10);
//            c = s / 10;
//            p = p->next;
//            l1 = l1?l1->next:l1;
//            l2 = l2?l2->next:l2;
//        }
//        p = h;
//        h = h->next;
//        free(p);
//        return h;
//    }
//};
