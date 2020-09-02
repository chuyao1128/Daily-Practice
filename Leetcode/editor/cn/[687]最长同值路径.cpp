//给定一个二叉树，找到最长的路径，这个路径中的每个节点具有相同值。 这条路径可以经过也可以不经过根节点。
//
// 注意：两个节点之间的路径长度由它们之间的边数表示。
//
// 示例 1:
//
// 输入:
//
//
//              5
//             / \
//            4   5
//           / \   \
//          1   1   5
//
//
// 输出:
//
//
//2
//
//
// 示例 2:
//
// 输入:
//
//
//              1
//             / \
//            4   5
//           / \   \
//          4   4   5
//
//
// 输出:
//
//
//2
//
//
// 注意: 给定的二叉树不超过10000个结点。 树的高度不超过1000。
// Related Topics 树 递归
// 👍 347 👎 0


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
    int ans = 0;

    //    1、计算以当前节点为根、且经过当前节点的最长单侧路径的边数，该值用来返回给父节点。
    //    2、对每一个节点计算以当前节点为根、且经过当前节点的最长路径（双侧）的边数，所有节点中的最大值即是要求的结果。
    int help(TreeNode *root) {
        if (root == nullptr)
            return 0;
        int left = help(root->left);
        int right = help(root->right);
        int longestL = 0;
        int longestR = 0;
        if (root->left != nullptr && root->left->val == root->val)
            longestL += left + 1;
        if (root->right != nullptr && root->right->val == root->val)
            longestR += right + 1;
        ans = max(ans, longestL + longestR);
        return max(longestL, longestR);//返回包括root本身所在的单侧"最长"同值路径的长度
    }

    int longestUnivaluePath(TreeNode *root) {
        help(root);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
