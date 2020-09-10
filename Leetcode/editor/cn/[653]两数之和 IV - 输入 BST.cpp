//给定一个二叉搜索树和一个目标结果，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。
//
// 案例 1:
//
//
//输入:
//    5
//   / \
//  3   6
// / \   \
//2   4   7
//
//Target = 9
//
//输出: True
//
//
//
//
// 案例 2:
//
//
//输入:
//    5
//   / \
//  3   6
// / \   \
//2   4   7
//
//Target = 28
//
//输出: False
//
//
//
// Related Topics 树
// 👍 171 👎 0


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
    vector<int> nums;

public:
    void inOrder(TreeNode *root) {
        if (!root)
            return;
        inOrder(root->left);
        nums.push_back(root->val);
        inOrder(root->right);
    }
    bool findTarget(TreeNode *root, int k) {
        inOrder(root);
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int sum = nums[l] + nums[r];
            if (sum == k)
                return true;
            if (sum < k)
                l++;
            else
                r--;
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
