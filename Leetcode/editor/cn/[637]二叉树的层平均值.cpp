//给定一个非空二叉树, 返回一个由每层节点平均值组成的数组。
//
//
//
// 示例 1：
//
// 输入：
//    3
//   / \
//  9  20
//    /  \
//   15   7
//输出：[3, 14.5, 11]
//解释：
//第 0 层的平均值是 3 ,  第1层是 14.5 , 第2层是 11 。因此返回 [3, 14.5, 11] 。
//
//
//
//
// 提示：
//
//
// 节点值的范围在32位有符号整数范围内。
//
// Related Topics 树
// 👍 158 👎 0


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
    vector<double> res;

    void bfs(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            double sum = 0;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode *temp = q.front();
                q.pop();
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
                sum += temp->val;
            }
            res.push_back(sum / n);
        }
    }

    vector<double> averageOfLevels(TreeNode *root) {
        bfs(root);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
