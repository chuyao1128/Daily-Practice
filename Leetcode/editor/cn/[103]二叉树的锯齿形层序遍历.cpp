//给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
//
// 例如：
//给定二叉树 [3,9,20,null,null,15,7],
//
//
//    3
//   / \
//  9  20
//    /  \
//   15   7
//
//
// 返回锯齿形层序遍历如下：
//
//
//[
//  [3],
//  [20,9],
//  [15,7]
//]
//
// Related Topics 栈 树 广度优先搜索
// 👍 338 👎 0


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
    vector<vector<int>> res;

public:
    void bfs(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);
        bool leftFlag = true;

        while (!q.empty()) {
            deque<int> level;//双向队列
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *cur = q.front();
                q.pop();
                if (leftFlag) {
                    level.emplace_back(cur->val);//emplace_back效率高于push_back,总是忘
                } else {
                    level.emplace_front(cur->val);
                }
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
            }
            res.emplace_back(vector<int>{level.begin(), level.end()});
            leftFlag = !leftFlag;
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (!root) {
            return res;
        }
        bfs(root);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
