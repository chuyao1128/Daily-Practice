//给定一个二叉树，返回所有从根节点到叶子节点的路径。
//
// 说明: 叶子节点是指没有子节点的节点。
//
// 示例:
//
// 输入:
//
//   1
// /   \
//2     3
// \
//  5
//
//输出: ["1->2->5", "1->3"]
//
//解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
// Related Topics 树 深度优先搜索
// 👍 345 👎 0


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
    vector<string> res;

public:
    void dfs(TreeNode *root, string path) {
        path += to_string(root->val);
        if (!root->left && !root->right)
            res.push_back(path);
        if (root->left)
            dfs(root->left, path + "->");
        if (root->right)
            dfs(root->right, path + "->");
    }
    vector<string> binaryTreePaths(TreeNode *root) {
        if (!root)
            return {};
        dfs(root, "");
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
