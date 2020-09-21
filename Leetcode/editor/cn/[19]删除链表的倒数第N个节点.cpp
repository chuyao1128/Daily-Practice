//给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
//
// 示例：
//
// 给定一个链表: 1->2->3->4->5, 和 n = 2.
//
//当删除了倒数第二个节点后，链表变为 1->2->3->5.
//
//
// 说明：
//
// 给定的 n 保证是有效的。
//
// 进阶：
//
// 你能尝试使用一趟扫描实现吗？
// Related Topics 链表 双指针
// 👍 991 👎 0


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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *preHead = new ListNode(0);
        preHead->next = head; //虚拟头节点
        ListNode *p = preHead;//快指针
        ListNode *q = preHead;//慢指针
        while (n--) {
            p = p->next;
        }
        //追赶
        while (p->next) {
            p = p->next;
            q = q->next;
        }
        q->next = q->next->next;//删除目标节点
        return preHead->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
