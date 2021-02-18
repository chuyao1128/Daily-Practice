//输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。 
//
// 
//
// 例如，给出 
//
// 前序遍历 preorder = [3,9,20,15,7]
//中序遍历 inorder = [9,3,15,20,7] 
//
// 返回如下的二叉树： 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7 
//
// 
//
// 限制： 
//
// 0 <= 节点个数 <= 5000 
//
// 
//
// 注意：本题与主站 105 题重复：https://leetcode-cn.com/problems/construct-binary-tree-from-
//preorder-and-inorder-traversal/ 
// Related Topics 树 递归 
// 👍 318 👎 0


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
    unordered_map<int, int> index;
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() != inorder.size() || preorder.size() == 0) {
            return nullptr;
        }
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            index[inorder[i]] = i; //建立值-对应索引下标的hash表
        }
        return reBuild(preorder, inorder, 0, n - 1, 0, n - 1);
    }

    TreeNode *
    reBuild(vector<int> &preorder, vector<int> &inorder, int pre_start, int pre_end, int in_start, int in_end) {
        if (pre_start > pre_end) {
            return nullptr;
        }
        int pre_root = pre_start; //前序遍历第一个为根节点
        int in_root = index[preorder[pre_root]]; //根节点在中序遍历中的下标
        TreeNode *root = new TreeNode(preorder[pre_root]); //建树
        int left_size = in_root - in_start; //左子树大小
        //递归构造左子树
        root->left = reBuild(preorder, inorder, pre_start + 1, pre_start + left_size, in_start, in_root - 1);
        //递归构造右子树
        root->right = reBuild(preorder, inorder, pre_start + left_size + 1, pre_end, in_root + 1, in_end);
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
