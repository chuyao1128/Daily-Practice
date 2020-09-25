//根据一棵树的中序遍历与后序遍历构造二叉树。
//
// 注意:
//你可以假设树中没有重复的元素。
//
// 例如，给出
//
// 中序遍历 inorder = [9,3,15,20,7]
//后序遍历 postorder = [9,15,7,20,3]
//
// 返回如下的二叉树：
//
//     3
//   / \
//  9  20
//    /  \
//   15   7
//
// Related Topics 树 深度优先搜索 数组
// 👍 337 👎 0


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
    unordered_map<int, int> inxMap;
    int post;

public:
    TreeNode *helper(vector<int> &inorder, vector<int> &postorder, int inL, int inR) {
        if (inL > inR)
            return nullptr;
        TreeNode *root = new TreeNode(postorder[post]);
        int index = inxMap[postorder[post]];
        post--;
        root->right = helper(inorder, postorder, index + 1, inR);
        root->left = helper(inorder, postorder, inL, index - 1);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inxMap[inorder[i]] = i;
        }
        post = postorder.size() - 1;
        return helper(inorder, postorder, 0, inorder.size() - 1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
