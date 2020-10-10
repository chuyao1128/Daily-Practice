//给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。 
//
// 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。 
//
// 说明：不允许修改给定的链表。 
//
// 
//
// 示例 1： 
//
// 输入：head = [3,2,0,-4], pos = 1
//输出：tail connects to node index 1
//解释：链表中有一个环，其尾部连接到第二个节点。
// 
//
// 
//
// 示例 2： 
//
// 输入：head = [1,2], pos = 0
//输出：tail connects to node index 0
//解释：链表中有一个环，其尾部连接到第一个节点。
// 
//
// 
//
// 示例 3： 
//
// 输入：head = [1], pos = -1
//输出：no cycle
//解释：链表中没有环。
// 
//
// 
//
// 
//
// 进阶： 
//你是否可以不用额外空间解决此题？ 
// Related Topics 链表 双指针 
// 👍 662 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


//相遇时：
//slow走过的路程：x + y + n(y+z), n代表slow绕了n圈
//fast走过的路程：x + y + m(y+z)，m代表fast饶了m圈
//m > n
//因为fast速度是slow两倍：
//2(x + y + n(y + z)) = x + y + m(y + z)
//x + y = (m - 2n)(y + z)
//x = (m - 2n)(y + z) - y
//y + z就是1圈，假设 o = m-2n，o是一个正整数，那么 x = o(y + z) -y
//如果o = 1，那么 x = z，
//如果o > 1，那么 x = (o-1)(y+z)- y + (y + z) , x = (o-1)(y+z) + z，即x的长度为o-1圈加上z
//所以，从第一阶段获得的相遇点，走过x距离机会到达环的起点。


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                ListNode *ptr = head;
                while (ptr != slow) {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        return nullptr;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
