//给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
//
// 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（
//一个节点也可以是它自己的祖先）。”
//
// 例如，给定如下二叉树: root = [3,5,1,6,2,0,8,null,null,7,4]
//
//
//
//
//
// 示例 1:
//
// 输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
//输出: 3
//解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
//
//
// 示例 2:
//
// 输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
//输出: 5
//解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。
//
//
//
//
// 说明:
//
//
// 所有节点的值都是唯一的。
// p、q 为不同节点且均存在于给定的二叉树中。
//
// Related Topics 树
// 👍 727 👎 0


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

//根据235题思路
class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root || p == root || q == root)
            return root;
        TreeNode *L = lowestCommonAncestor(root->left, p, q);
        TreeNode *R = lowestCommonAncestor(root->right, p, q);
        if (L == nullptr)
            return R;
        if (R == nullptr)
            return L;
        return root;
    }
};

//官方题解思路
class Solution_2 {
private:
    TreeNode *ans;

public:
    bool dfs(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root)
            return false;
        bool lson = dfs(root->left, p, q); //左子树中是否有p、q
        bool rson = dfs(root->right, p, q);//右子树中是否有p、q
        //符合条件：1.左子树和右子树均包含p节点或q节点
        //2.root恰好是p节点或q节点且它的左子树或右子树有一个包含了另一个节点
        if ((lson && rson) || ((lson || rson) && (root->val == p->val || root->val == q->val)))
            ans = root;
        return root->val == p->val || root->val == q->val || lson || rson;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        dfs(root, p, q);
        return ans;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
