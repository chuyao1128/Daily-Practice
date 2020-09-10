//给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。
//
//
//
// 示例：
//
// 输入：
//
//   1
//    \
//     3
//    /
//   2
//
//输出：
//1
//
//解释：
//最小绝对差为 1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。
//
//
//
//
// 提示：
//
//
// 树中至少有 2 个节点。
// 本题与 783 https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/
//相同
//
// Related Topics 树
// 👍 135 👎 0


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

//中序遍历得到递增序列，最小值为序列中连续两元素的最小差值
class Solution {
private:
    int res = INT_MAX;
    int prev = -1;

public:
    void dfs(TreeNode *root) {
        if (!root)
            return;
        dfs(root->left);
        if (prev >= 0)
            res = min(res, root->val - prev);
        prev = root->val;
        dfs(root->right);
    }
    int getMinimumDifference(TreeNode *root) {
        dfs(root);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
