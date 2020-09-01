//给定一个二叉树，判断它是否是高度平衡的二叉树。
//
// 本题中，一棵高度平衡二叉树定义为：
//
//
// 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
//
//
// 示例 1:
//
// 给定二叉树 [3,9,20,null,null,15,7]
//
//     3
//   / \
//  9  20
//    /  \
//   15   7
//
// 返回 true 。
//
//示例 2:
//
// 给定二叉树 [1,2,2,3,3,null,null,4,4]
//
//        1
//      / \
//     2   2
//    / \
//   3   3
//  / \
// 4   4
//
//
// 返回 false 。
//
//
// Related Topics 树 深度优先搜索
// 👍 461 👎 0


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

/**
 * 自顶向下递归
 * 有了计算节点高度的函数，即可判断二叉树是否平衡。具体做法类似于二叉树的前序遍历，
 * 即对于当前遍历到的节点，首先计算左右子树的高度，如果左右子树的高度差是否不超过 11，
 * 再分别递归地遍历左右子节点，并判断左子树和右子树是否平衡。这是一个自顶向下的递归的过程。
 *
 * 时间复杂度：O(n ^ 2)，其中n是二叉树中的节点个数。
 */
class Solution {
public:
    int height(TreeNode *root) {
        if (root == NULL)
            return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
    bool isBalanced(TreeNode *root) {
        if (root == NULL)
            return true;
        return abs(height(root->left) - height(root->right)) < 2 && isBalanced(root->left) && isBalanced(root->right);
    }
};

/**
     * 自底向上递归
     * 方法一由于是自顶向下递归，因此对于同一个节点，函数height会被重复调用，
     * 导致时间复杂度较高。如果使用自底向上的做法，则对于每个节点，函数height只会被调用一次。
     * 自底向上递归的做法类似于后序遍历，对于当前遍历到的节点，先递归地判断其左右子树是否平衡，
     * 再判断以当前节点为根的子树是否平衡。如果一棵子树是平衡的，则返回其高度（高度一定是非负整数），
     * 否则返回 -1−1。如果存在一棵子树不平衡，则整个二叉树一定不平衡。
     *
     *时间复杂度：O(n)
**/
class Solution {
public:
    int height(TreeNode *root) {
        if (root == NULL)
            return 0;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if (abs(leftHeight - rightHeight) >= 2 || leftHeight == -1 || rightHeight == -1)
            return -1;
        else
            return max(leftHeight, rightHeight) + 1;
    }
    bool isBalanced(TreeNode *root) {
        if (height(root) >= 0)
            return true;
        else
            return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
