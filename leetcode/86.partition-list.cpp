/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
 *
 * https://leetcode.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (38.98%)
 * Likes:    1276
 * Dislikes: 296
 * Total Accepted:    214.8K
 * Total Submissions: 522.1K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * Given a linked list and a value x, partition it such that all nodes less
 * than x come before nodes greater than or equal to x.
 * 
 * You should preserve the original relative order of the nodes in each of the
 * two partitions.
 * 
 * Example:
 * 
 * 
 * Input: head = 1->4->3->2->5->2, x = 3
 * Output: 1->2->2->4->3->5
 * 
 * 
 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *head_ge = new ListNode();
        ListNode *head_lt = new ListNode();
        ListNode *node_ge = head_ge, *node_lt = head_lt;
        for (auto p = head; p != nullptr; p = p->next) {
            if (p->val < x) {
                node_lt->next = p;
                node_lt = p;
            } else {
                node_ge->next = p;
                node_ge = p;
            }
        }
        node_lt->next = head_ge->next;
        node_ge->next = nullptr;
        head = head_lt->next;

        // delete pre-head node
        head_lt->next = nullptr;
        delete head_lt;
        head_ge->next = nullptr;
        delete head_ge;

        return head;
    }
};
// @lc code=end
