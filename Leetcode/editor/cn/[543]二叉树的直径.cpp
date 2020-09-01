//给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。
//
//
//
// 示例 :
//给定二叉树
//
//           1
//         / \
//        2   3
//       / \     
//      4   5
//
//
// 返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。
//
//
//
// 注意：两结点之间的路径长度是以它们之间边的数目表示。
// Related Topics 树
// 👍 462 👎 0


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
    int ans;
    int depth(TreeNode *root) {
        if (root == NULL)
            return 0;
        int L = depth(root->left);
        int R = depth(root->right);
        ans = max(ans, L + R + 1);//root经过节点数的最大值，更新ans
        return max(L, R) + 1;     //返回root的深度
    }

public:
    int diameterOfBinaryTree(TreeNode *root) {
        ans = 1;       //初始化
        depth(root);   //求root深度以更新ans值
        return ans - 1;//直径为经过节点数最大值-1（路径）
    }
};
//leetcode submit region end(Prohibit modification and deletion)
