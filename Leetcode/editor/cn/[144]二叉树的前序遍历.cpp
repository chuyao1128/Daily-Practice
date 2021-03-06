//给定一个二叉树，返回它的 前序 遍历。
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
//输出: [1,2,3]
//
//
// 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
// Related Topics 栈 树
// 👍 356 👎 0


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
    vector<int> preorderTraversal(TreeNode *root) {
        if (!root)
            return {};
        vector<int> ans;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode *temp = st.top();
            ans.push_back(temp->val);
            st.pop();
            if (temp->right)
                st.push(temp->right);
            if (temp->left)
                st.push(temp->left);
        }
        return ans;
    }
};

//前/中/后序遍历统一写法
class Solution_2 {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        if (!root)
            return {};
        vector<int> res;
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *cur = s.top();
            s.pop();//访问过的节点弹出，避免重复操作，再将中左右节点入栈
            if (cur != nullptr) {
                if (cur->right)//右节点入栈
                    s.push(cur->right);
                if (cur->left)//左节点入栈
                    s.push(cur->left);
                s.push(cur);                //中节点入栈
                s.push(nullptr);            //中节点已经访问过，还没有被处理，用nullptr做标记
            } else {                        //空节点表示已访问过
                res.push_back(s.top()->val);//s.top()是nullptr之前入栈的节点，即s.push(cur)中的cur
                s.pop();                    //处理完后彻底移除
            }
        }
        return res;
    }
};


//leetcode submit region end(Prohibit modification and deletion)
