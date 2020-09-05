//给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。 
//
// 说明： 
//你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。 
//
// 示例 1: 
//
// 输入: root = [3,1,4,null,2], k = 1
//   3
//  / \
// 1   4
//  \
//   2
//输出: 1 
//
// 示例 2: 
//
// 输入: root = [5,3,6,2,4,null,null,1], k = 3
//       5
//      / \
//     3   6
//    / \
//   2   4
//  /
// 1
//输出: 3 
//
// 进阶： 
//如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化 kthSmallest 函数？ 
// Related Topics 树 二分查找 
// 👍 273 👎 0


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
    int flag;
    int ans;
public:
    void dfs(TreeNode *root, int k) {
        if (!root)
            return;
        dfs(root->left, k);
        flag++;
        if (flag == k) {
            ans = root->val;
        }
        dfs(root->right, k);
    }

    int kthSmallest(TreeNode *root, int k) {
        flag = 0;
        dfs(root, k);
        return ans;
    }
};

/**
 * 优化：如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化 kthSmallest 函数？
 * 记忆化BST
 * 新增两个变量 leftchilds和 rightchilds，分别记录该结点左子树和右子树中结点的数量。
 */
class Solution_memo {
private:
    unordered_map<TreeNode *, int> leftchilds;  //左子树中节点数量
    unordered_map<TreeNode *, int> rightchilds;  //右子树中节点数量
public:
    int myKthSmallest(TreeNode *root, int k) {
        TreeNode *cur = root; //cur一开始指向根结点
        int rank = leftchilds[cur] + 1; //rank是cur当前指向结点的排名（即第rank小）
        while (k != rank) {
            if (k < rank) {
                cur = cur->left;
                rank -= rightchilds[cur] + 1; //因为上一个根结点和当前根结点的右子树结点都排在当前结点后面，当前结点的排名相当于前进了cur -> rightchilds + 1个位置
            } else {
                cur = cur->right;
                rank += leftchilds[cur] + 1; //因为上一个根结点和当前根结点的左子树结点都排在当前结点前面，当前结点的排名相当于后退了cur -> leftchilds + 1个位置
            }
        }
        return cur->val;
    }

    int memoTree(TreeNode *root) {
        if (!root) {
            return 0;
        }
        leftchilds[root] = memoTree(root->left);
        rightchilds[root] = memoTree(root->right);
        return leftchilds[root] + rightchilds[root] + 1;
    }

    int kthSmallest(TreeNode *root, int k) {
        if (!root) {
            return 0;
        }
        memoTree(root);
        return myKthSmallest(root, k);
    }

};

//leetcode submit region end(Prohibit modification and deletion)
