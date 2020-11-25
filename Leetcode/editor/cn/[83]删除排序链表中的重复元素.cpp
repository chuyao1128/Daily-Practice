//给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
//
// 示例 1:
//
// 输入: 1->1->2
//输出: 1->2
//
//
// 示例 2:
//
// 输入: 1->1->2->3->3
//输出: 1->2->3
// Related Topics 链表
// 👍 430 👎 0


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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *temp = head;
        while (head && head->next) {
            if (head->val == head->next->val) {
                ListNode *del = head->next;
                head->next = del->next;
                delete del;
            } else {
                head = head->next;
            }
        }
        return temp;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
