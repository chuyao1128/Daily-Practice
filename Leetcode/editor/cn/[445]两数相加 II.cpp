//给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
//
// 你可以假设除了数字 0 之外，这两个数字都不会以零开头。
//
//
//
// 进阶：
//
// 如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。
//
//
//
// 示例：
//
// 输入：(7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
//输出：7 -> 8 -> 0 -> 7
//
// Related Topics 链表
// 👍 276 👎 0


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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (!l1 || !l2) {
            return l1 == nullptr ? l2 : l1;
        }
        int carried = 0;//进位
        int a, b, sum;
        stack<int> s1, s2;
        ListNode *res = nullptr;//创建头节点
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        while (!s1.empty() || !s2.empty() || carried) {
            a = s1.empty() ? 0 : s1.top();
            b = s2.empty() ? 0 : s2.top();
            if (!s1.empty())
                s1.pop();
            if (!s2.empty())
                s2.pop();
            sum = a + b + carried;
            carried = sum / 10;
            sum %= 10;
            ListNode *cur = new ListNode(sum);
            cur->next = res;
            res = cur;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
