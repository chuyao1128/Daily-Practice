//给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
//
// 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
//
//
//
// 示例:
//
// 给定 1->2->3->4, 你应该返回 2->1->4->3.
//
// Related Topics 链表
// 👍 628 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
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
    ListNode *swapPairs(ListNode *head) {
        ListNode *prehead = new ListNode(0);
        prehead->next = head;
        ListNode *cur = prehead;
        ListNode *p = head;
        ListNode *q, *temp;
        while (p && p->next) {
            q = p->next;
            cur->next = q;
            p->next = q->next;
            q->next = p;
            cur = p;
            p = p->next;
        }
        return prehead->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
