//给定一个二叉树，返回它的 后序 遍历。
//
// 示例:
//
// 输入: [1,null,2,3]
//   1
//    \
//     2
//    /
//   3
//
//输出: [3,2,1]
//
// 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
// Related Topics 栈 树
// 👍 386 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        if (!root)
            return {};
        vector<int> res;
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *cur = s.top();
            s.pop();//访问过的节点弹出，避免重复操作，再将中左右节点入栈
            if (cur != nullptr) {
                s.push(cur);    //中节点入栈
                s.push(nullptr);//中节点已经访问过，还没有被处理，用nullptr做标记
                if (cur->right) //右节点入栈
                    s.push(cur->right);
                if (cur->left)//左节点入栈
                    s.push(cur->left);
            } else {                        //空节点表示已访问过
                res.push_back(s.top()->val);//s.top()是nullptr之前入栈的节点，即s.push(cur)中的cur
                s.pop();                    //处理完后彻底移除
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
