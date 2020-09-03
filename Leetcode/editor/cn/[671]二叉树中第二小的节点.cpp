//给定一个非空特殊的二叉树，每个节点都是正数，并且每个节点的子节点数量只能为 2 或 0。如果一个节点有两个子节点的话，那么该节点的值等于两个子节点中较小的一
//个。
//
// 给出这样的一个二叉树，你需要输出所有节点中的第二小的值。如果第二小的值不存在的话，输出 -1 。
//
// 示例 1:
//
// 输入:
//    2
//   / \
//  2   5
//     / \
//    5   7
//
//输出: 5
//说明: 最小的值是 2 ，第二小的值是 5 。
//
//
// 示例 2:
//
// 输入:
//    2
//   / \
//  2   2
//
//输出: -1
//说明: 最小的值是 2, 但是不存在第二小的值。
//
// Related Topics 树
// 👍 100 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int findSecondMinimumValue(TreeNode *root) {
        if (!root || !root->left || !root->right)
            return -1;
        int l = root->left->val;
        int r = root->right->val;
        if (root->val == root->left->val)
            l = findSecondMinimumValue(root->left);//左子树最小值
        if (root->val == root->right->val)
            r = findSecondMinimumValue(root->right);//右子树最小值
        if (root->val == l == r)
            return -1;
        return root->val < min(l, r) ? min(l, r) : max(l, r);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
