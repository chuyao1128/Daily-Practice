//翻转一棵二叉树。
//
// 示例：
//
// 输入：
//
//      4
//   /   \
//  2     7
// / \   / \
//1   3 6   9
//
// 输出：
//
//      4
//   /   \
//  7     2
// / \   / \
//9   6 3   1
//
// 备注:
//这个问题是受到 Max Howell 的 原问题 启发的 ：
//
// 谷歌：我们90％的工程师使用您编写的软件(Homebrew)，但是您却无法在面试时在白板上写出翻转二叉树这道题，这太糟糕了。
// Related Topics 树
// 👍 556 👎 0


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

//递归
class Solution {
public:
    TreeNode *invertTree(TreeNode *root) {
        if (root == NULL)
            return root;
        if (root->left != NULL || root->right != NULL) {
            swap(root->left, root->right);
            invertTree(root->left);
            invertTree(root->right);
        }
        return root;
    }
};

//迭代
class Solution_2 {
public:
    TreeNode *invertTree(TreeNode *root) {
        if (root == NULL)
            return root;
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *cur = s.top();
            s.pop();
            swap(cur->left, cur->right);
            if (cur->left)
                s.push(cur->left);
            if (cur->right)
                s.push(cur->right);
        }
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
