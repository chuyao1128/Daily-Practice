//给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。
//
// 假定 BST 有如下定义：
//
//
// 结点左子树中所含结点的值小于等于当前结点的值
// 结点右子树中所含结点的值大于等于当前结点的值
// 左子树和右子树都是二叉搜索树
//
//
// 例如：
//给定 BST [1,null,2,2],
//
//    1
//    \
//     2
//    /
//   2
//
//
// 返回[2].
//
// 提示：如果众数超过1个，不需考虑输出顺序
//
// 进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）
// Related Topics 树
// 👍 143 👎 0


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
private:
    int count = 1;
    int max = 1;
    TreeNode *pre = nullptr;
    vector<int> res;

public:
    void dfs(TreeNode *root) {
        if (!root)
            return;
        dfs(root->left);
        if (pre && root->val == pre->val)
            count++;
        else
            count = 1;
        if (count > max) {
            max = count;
            res.clear();
            res.push_back(root->val);
        } else if (count == max)
            res.push_back(root->val);
        pre = root;
        dfs(root->right);
    }
    vector<int> findMode(TreeNode *root) {
        if (!root)
            return {};
        dfs(root);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
