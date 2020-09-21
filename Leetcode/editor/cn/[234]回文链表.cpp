//请判断一个链表是否为回文链表。
//
// 示例 1:
//
// 输入: 1->2
//输出: false
//
// 示例 2:
//
// 输入: 1->2->2->1
//输出: true
//
//
// 进阶：
//你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
// Related Topics 链表 双指针
// 👍 643 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//数组
class Solution {
public:
    bool isPalindrome(ListNode *head) {
        vector<int> nums;
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            if (nums[i] != nums[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};

//栈
class Solution_2 {
public:
    bool isPalindrome(ListNode *head) {
        stack<int> s;
        ListNode *cur = head;
        while (cur) {
            s.push(cur->val);
            cur = cur->next;
        }
        int i = s.size() / 2;
        while (i) {
            if (head->val != s.top())
                return false;
            s.pop();
            head = head->next;
            i--;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
