class Solution {
public:
    ListNode* reverse(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        ListNode* pre = head;
        ListNode* p = pre->next;
        head->next = nullptr;
        while (p) {
            ListNode* q = p->next;
            p->next = pre;
            pre = p;
            p = q;
        }
        return pre;
    }
    inline ListNode* removePreHead(ListNode* preHead) {
        ListNode* head = preHead->next;
        free(preHead);
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* preHead = new ListNode(0);
        preHead->next = head;
        ListNode* pre = preHead;
        ListNode* p = pre->next;

        while(p) {
            for (int i = 1; i < k; i ++) {
                p = p->next;
                if (!p) return removePreHead(preHead);
            }
            ListNode* next = p->next;
            p->next = NULL;
            // reverse List: curHead -> ... -> tail :to: curHead <- ... <- p
            ListNode* curHead = reverse(pre->next);
            ListNode* curTail = pre->next;
            // link again
            pre->next = curHead;
            curTail->next = next;
            // next iter
            pre = curTail;
            p = curTail->next;
        }
        return removePreHead(preHead);
    }
};
