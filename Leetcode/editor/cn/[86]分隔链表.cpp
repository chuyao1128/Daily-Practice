//给你一个链表和一个特定值 x ，请你对链表进行分隔，使得所有小于 x 的节点都出现在大于或等于 x 的节点之前。
//
// 你应当保留两个分区中每个节点的初始相对位置。
//
//
//
// 示例：
//
//
//输入：head = 1->4->3->2->5->2, x = 3
//输出：1->2->2->4->3->5
//
// Related Topics 链表 双指针
// 👍 345 👎 0


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
    ListNode *partition(ListNode *head, int x) {
        ListNode *smallHead = new ListNode(0);
        ListNode *small = smallHead;
        ListNode *largeHead = new ListNode(0);
        ListNode *large = largeHead;
        while (head) {
            if (head->val < x) {
                small->next = head;
                small = small->next;
            } else {
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }
        large->next = nullptr;
        small->next = largeHead->next;
        return smallHead->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
