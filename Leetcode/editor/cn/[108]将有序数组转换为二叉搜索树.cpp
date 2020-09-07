//将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
//
// 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
//
// 示例:
//
// 给定有序数组: [-10,-3,0,5,9],
//
//一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：
//
//      0
//     / \
//   -3   9
//   /   /
// -10  5
//
// Related Topics 树 深度优先搜索
// 👍 573 👎 0


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
    TreeNode *buildBST(vector<int> &nums, int left, int right) {
        if (left > right)
            return nullptr;
        int index = (left + right + rand() % 2) / 2;//随机选取中间位置的数字作为根节点
        TreeNode *root = new TreeNode(nums[index]);
        root->left = buildBST(nums, left, index - 1);
        root->right = buildBST(nums, index + 1, right);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return buildBST(nums, 0, nums.size() - 1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
