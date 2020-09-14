//给定一个二叉树，返回它的中序 遍历。
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
//输出: [1,3,2]
//
// 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
// Related Topics 栈 树 哈希表
// 👍 654 👎 0


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

//2020-9-04
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        if (!root)
            return {};
        vector<int> res;
        stack < TreeNode * > s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *cur = s.top();
            s.pop();
            if (cur != nullptr) {
                if (cur->right)
                    s.push(cur->right);
                s.push(cur);
                s.push(nullptr);
                if (cur->left)
                    s.push(cur->left);
            } else {
                res.push_back(s.top()->val);
                s.pop();
            }
        }
        return res;
    }
};

//2020-9-14
class Solution_2 {
private:
    vector<int> res;
public:
    void dfs(TreeNode *root) {
        if (!root)
            return;
        stack < TreeNode * > s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *cur = s.top();
            s.pop();
            if (cur != nullptr) {
                if (cur->right)
                    s.push(cur->right);
                s.push(cur);
                s.push(nullptr);
                if (cur->left)
                    s.push(cur->left);
            } else {
                res.push_back(s.top()->val);
                s.pop();
            }
        }
    }

    vector<int> inorderTraversal(TreeNode *root) {
        if (!root)
            return {};
        dfs(root);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
